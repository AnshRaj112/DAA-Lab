#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Binary counter with amortized O(1) INCREMENT and RESET

  Idea: Use a generation/timestamp trick. A bit is logically 1 iff
        lastSetGen[i] == currentGen. RESET is just currentGen++ and
        high = -1, so it's O(1). INCREMENT flips trailing ones to zero
        and sets the next zero to one, updating timestamps as needed.

  Cost model: examining/modifying any bit is O(1). Any sequence of n
  operations (INCREMENT/RESET) runs in O(n) time from an all-zero start.

  Input (simple REPL):
    First line: capacity m (number of bits)
    Then commands until EOF:
      INC
      RESET
      PRINT
*/

typedef struct {
    int capacity;
    int *lastSetGen;   /* timestamp when this bit was last set to 1 */
    int currentGen;    /* generation counter */
    int high;          /* index of highest 1 bit, -1 if none */
} GenCounter;

static GenCounter make_counter_1653(int m) {
    GenCounter c;
    c.capacity = m;
    c.lastSetGen = (int *)malloc((size_t)m * sizeof(int));
    if (!c.lastSetGen) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    for (int i = 0; i < m; ++i) c.lastSetGen[i] = -1;
    c.currentGen = 0;
    c.high = -1;
    return c;
}

static int get_bit_1653(const GenCounter *c, int i) {
    return c->lastSetGen[i] == c->currentGen;
}

static void set_bit_1653(GenCounter *c, int i) {
    c->lastSetGen[i] = c->currentGen;
    if (i > c->high) c->high = i;
}

static void clear_bit_1653(GenCounter *c, int i) {
    /* Clear by moving it to a past generation */
    if (get_bit_1653(c, i)) {
        c->lastSetGen[i] = c->currentGen - 1;
        if (i == c->high) {
            while (c->high >= 0 && !get_bit_1653(c, c->high)) c->high--;
        }
    }
}

static void increment_1653(GenCounter *c) {
    /* Flip trailing ones to zero */
    int i = 0;
    while (i < c->capacity && get_bit_1653(c, i)) {
        clear_bit_1653(c, i);
        ++i;
    }
    if (i == c->capacity) {
        /* overflow: ignore or clamp */
        return;
    }
    set_bit_1653(c, i);
}

static void reset_counter_1653(GenCounter *c) {
    /* O(1) lazy reset via generation bump */
    c->currentGen += 1;
    c->high = -1;
}

static void print_counter_1653(const GenCounter *c) {
    if (c->high < 0) {
        printf("0\n");
        return;
    }
    for (int i = c->high; i >= 0; --i) putchar(get_bit_1653(c, i) ? '1' : '0');
    putchar('\n');
}

int main(void) {
    int m;
    if (scanf("%d", &m) != 1 || m <= 0) {
        fprintf(stderr, "Invalid capacity\n");
        return 1;
    }
    GenCounter ctr = make_counter_1653(m);
    char cmd[32];
    while (scanf("%31s", cmd) == 1) {
        if (strcmp(cmd, "INC") == 0) {
            increment_1653(&ctr);
        } else if (strcmp(cmd, "RESET") == 0) {
            reset_counter_1653(&ctr);
        } else if (strcmp(cmd, "PRINT") == 0) {
            print_counter_1653(&ctr);
        } else {
            fprintf(stderr, "Unknown command: %s\n", cmd);
        }
    }
    free(ctr.lastSetGen);
    return 0;
}


