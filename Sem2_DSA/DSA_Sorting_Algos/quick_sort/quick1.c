#include <stdio.h>

/* Utility to print array */
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
}

/* Swap function with trace */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Lomuto partition with detailed tracing */
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    printf("\n--- Partitioning range [%d .. %d] ---\n", low, high);
    printf("Pivot picked (last element): %d\n", pivot);
    printf("Before partition: ");
    printArray(arr, n);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        printf("Compare arr[%d] = %d with pivot %d : ", j, arr[j], pivot);

        if (arr[j] <= pivot) {
            i++;
            printf("<= pivot → swap arr[%d] and arr[%d]\n", i, j);
            swap(&arr[i], &arr[j]);
            printf("Array now: ");
            printArray(arr, n);
        } else {
            printf("> pivot → no swap\n");
        }
    }

    printf("Place pivot in correct position by swapping arr[%d] and arr[%d]\n", i + 1, high);
    swap(&arr[i + 1], &arr[high]);

    printf("After placing pivot: ");
    printArray(arr, n);
    printf("Pivot %d fixed at index %d\n", arr[i + 1], i + 1);

    return i + 1;
}

/* Quick Sort with trace */
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);

        printf("\nLeft sub-array [%d .. %d]\n", low, pi - 1);
        quickSort(arr, low, pi - 1, n);

        printf("\nRight sub-array [%d .. %d]\n", pi + 1, high);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
    int arr[] = {7, 2, 9, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial Array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1, n);

    printf("\n==============================\n");
    printf("Final Sorted Array: ");
    printArray(arr, n);

    return 0;
}
