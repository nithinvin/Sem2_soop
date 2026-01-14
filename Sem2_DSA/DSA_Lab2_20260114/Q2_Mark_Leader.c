#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int bigger = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                bigger = 0;
                break;
            }
        }

        if (bigger) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
