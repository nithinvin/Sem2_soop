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
        printf("minIndex initialized to i which is %d\n", minIndex);

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                printf("j is at %d, arr[j] is %d which is smaller than arr[minIndex] which is %d\n", j, arr[j], arr[minIndex]);
                minIndex = j;
                printf("minIndex becomes %d\n", minIndex);
            }
        }

        /* Swap only if needed */
        if (minIndex != i) {
            printf("arr[i] %d swapped with arr[minIndex] %d\n", minIndex);
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
