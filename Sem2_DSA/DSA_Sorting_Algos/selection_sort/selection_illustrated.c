#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j, minIndex, temp;
    int arr[100];

    /*
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    */
    n = 5;
    arr[0] = 7; arr[1] = 4; arr[2] = 9; arr[3] = 2; arr[4] = 6;

    printf("Initial array:\n");
    printArray(arr, n);

    /* Selection Sort */
    for (i = 0; i < n - 1; i++) {
        printf("Pass i = %d\n", i);
        minIndex = i;
        printf("minIndex = i, arr[minIndex] = (%d)\n", arr[minIndex]);

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                printf("j is at index %d, arr[j] (%d) and is smaller than arr[minIndex] (%d)\n", j, arr[j], arr[minIndex]);
                minIndex = j;
                printf("minIndex becomes %d - Value(%d)\n", minIndex, arr[minIndex]);
            } else {
                printf("j is at index %d, arr[j] (%d) and is NOT smaller than arr[minIndex] (%d)\n", j, arr[j], arr[minIndex]);
            }
        }

        /* Swap only if needed */
        if (minIndex != i) {
            printf("i = %d, minIndex = %d, arr[i] %d swapped with arr[minIndex] %d\n", i, minIndex, arr[i], arr[minIndex]);
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        printf("Current array:\n");
        printArray(arr, n);
        printf("\n");
    }

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
