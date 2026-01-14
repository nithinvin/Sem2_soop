#include <stdio.h>

void sort_ascending(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sort_descending(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    int arr[128];
    int even[64], odd[64];
    int eCount = 0, oCount = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {
            even[eCount++] = arr[i];
        } else {
            odd[oCount++] = arr[i];
        }
    }

    sort_ascending(even, eCount);
    sort_descending(odd, oCount);

    for (i = 0; i < eCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    for (i = 0; i < oCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}
