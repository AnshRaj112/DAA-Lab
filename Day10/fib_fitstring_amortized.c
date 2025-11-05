#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Fibonacci fitstring increment/decrement in amortized O(1)

  Representation:
    fit[i] is 0/1 indicating whether F_{i+2} is included (i = 0 => F2 = 1).
    Least significant fit at index 0.

  Invariant (normalized form): no two consecutive 1s in the fitstring
    (Zeckendorf representation). After each operation we re-normalize using
    local rewrites based on F_{k+1} = F_k + F_{k-1}.

  Operations:
    - INC: add 1 to the number
    - DEC: subtract 1 from the number (assuming > 0)

  Input (simple REPL):
    First line: initial fitstring as MSB..LSB over F (e.g., 101110 for 14)
    Then lines of commands until EOF:
      INC
      DEC
      PRINT

  Amortized analysis sketch:
    Each INC/DEC performs a constant number of local rewrites on average;
    cascades are charged to creation of 1s that will be eliminated later.
*/

typedef struct {
    int *bits;     /* bits[i] in {0,1} */
    int size;      /* allocated length */
    int used;      /* highest used index + 1 */
} FitString;

static void ensure_capacity_1653(FitString *fs, int min_cap) {
    if (min_cap <= fs->size) return;
    int new_cap = fs->size ? fs->size : 8;
    while (new_cap < min_cap) new_cap <<= 1;
    int *nb = (int *)realloc(fs->bits, (size_t)new_cap * sizeof(int));
    if (!nb) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    for (int i = fs->size; i < new_cap; ++i) nb[i] = 0;
    fs->bits = nb;
    fs->size = new_cap;
}

static FitString make_fitstring_from_msb_string_1653(const char *msb_first) {
    FitString fs = {0};
    int len = (int)strlen(msb_first);
    ensure_capacity_1653(&fs, len);
    fs.used = len;
    /* Input given MSB..LSB. We store LSB..MSB */
    for (int i = 0; i < len; ++i) {
        char c = msb_first[len - 1 - i];
        if (c == '0' || c == '1') fs.bits[i] = (c == '1');
        else fs.bits[i] = 0;
    }
    return fs;
}

static void trim_used_1653(FitString *fs) {
    while (fs->used > 0 && fs->bits[fs->used - 1] == 0) fs->used--;
}

static void normalize_1653(FitString *fs) {
    /* Eliminate consecutive ones: replace 011 -> 100 repeatedly */
    for (int i = 0; i + 1 < fs->used; ) {
        if (fs->bits[i] == 1 && fs->bits[i + 1] == 1) {
            /* 11 at i,i+1 becomes 0,0, and +1 at i+2 */
            fs->bits[i] = 0;
            fs->bits[i + 1] = 0;
            int k = i + 2;
            ensure_capacity_1653(fs, k + 1);
            if (k >= fs->used) fs->used = k + 1;
            /* add carry at k */
            while (1) {
                if (fs->bits[k] == 0) { fs->bits[k] = 1; break; }
                /* if we create another 1 next to 1, fold it immediately */
                fs->bits[k] = 0; /* 1+1 => 0 carry */
                k += 1;
                ensure_capacity_1653(fs, k + 1);
                if (k >= fs->used) fs->used = k + 1;
            }
            /* restart check safely one step back if possible */
            if (i > 0) --i; else i = 0;
        } else {
            ++i;
        }
    }
    /* If the highest two are 1s, normalize there too */
    trim_used_1653(fs);
}

static void increment_fit_1653(FitString *fs) {
    /* add F2 (index 0) */
    ensure_capacity_1653(fs, fs->used + 2);
    if (fs->used == 0) fs->used = 1;
    int i = 0;
    while (1) {
        if (i >= fs->used) fs->used = i + 1;
        if (fs->bits[i] == 0) { fs->bits[i] = 1; break; }
        fs->bits[i] = 0; /* carry to next Fibonacci place */
        ++i;
    }
    normalize_1653(fs);
}

static int is_zero_1653(const FitString *fs) {
    for (int i = 0; i < fs->used; ++i) if (fs->bits[i]) return 0;
    return 1;
}

static void decrement_fit_1653(FitString *fs) {
    if (is_zero_1653(fs)) return; /* no-op on zero */
    /* subtract F2 (index 0) with borrow from the first 1 above it */
    /* Case 1: LSB is 1 => simple flip */
    if (fs->bits[0] == 1) {
        fs->bits[0] = 0;
        normalize_1653(fs);
        return;
    }
    /* Case 2: find first i>0 with bit 1 (lower bits are 0 by definition) */
    int i = 1;
    while (i < fs->used && fs->bits[i] == 0) ++i;
    if (i >= fs->used) return; /* already zero (guarded), but be safe */
    /* Borrow: turn a 1 at i into a chain of 1s down to indices 1 and 0 via 100 -> 011 */
    fs->bits[i] = 0;
    for (int k = i - 1; k >= 1; --k) {
        /* Prior to normalization, lower bits are zero; we can safely set two ones */
        if (fs->bits[k] == 0) fs->bits[k] = 1; else fs->bits[k] = 1;
        if (fs->bits[k - 1] == 0) fs->bits[k - 1] = 1; else fs->bits[k - 1] = 1;
    }
    /* Now bit[0] must be 1; subtract 1 */
    fs->bits[0] = 0;
    normalize_1653(fs);
}

static void print_fitstring_msb_1653(const FitString *fs) {
    int msb = fs->used - 1;
    while (msb > 0 && fs->bits[msb] == 0) --msb;
    for (int i = msb; i >= 0; --i) putchar(fs->bits[i] ? '1' : '0');
    putchar('\n');
}

int main(void) {
    char buf[4096];
    if (!fgets(buf, sizeof(buf), stdin)) {
        fprintf(stderr, "Expected initial fitstring on first line\n");
        return 1;
    }
    /* strip newline */
    size_t blen = strlen(buf);
    if (blen && (buf[blen - 1] == '\n' || buf[blen - 1] == '\r')) buf[--blen] = '\0';

    FitString fs = make_fitstring_from_msb_string_1653(buf);
    normalize_1653(&fs);

    char cmd[32];
    while (scanf("%31s", cmd) == 1) {
        if (strcmp(cmd, "INC") == 0) {
            increment_fit_1653(&fs);
        } else if (strcmp(cmd, "DEC") == 0) {
            decrement_fit_1653(&fs);
        } else if (strcmp(cmd, "PRINT") == 0) {
            print_fitstring_msb_1653(&fs);
        } else {
            fprintf(stderr, "Unknown command: %s\n", cmd);
        }
    }

    free(fs.bits);
    return 0;
}


