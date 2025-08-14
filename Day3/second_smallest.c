//Find second smallest element in an array 

#include <stdio.h>

int main() {
    int arr[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int smallest = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] < smallest){
            smallest = arr[i];
        }
    }
    int second_smallest = arr[1];
    for (int i = 1; i < n; i++){
        if (arr[i] < second_smallest && arr[i] != smallest){
            second_smallest = arr[i];
        }
    }
    printf("The second smallest element in the array is %d", second_smallest);
    return 0;
}