#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 1};
    int n = 4;
    int temp;

    for (int i = 0; i < n - 1; i++) {
        printf("\nPass %d:\n", i + 1);

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    return 0;
}
