#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 1};
    int n = 4;
    int temp;

    for (int i = 0; i < n - 1; i++) {          // passes
        for (int j = 0; j < n - i - 1; j++) {  // comparisons
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
