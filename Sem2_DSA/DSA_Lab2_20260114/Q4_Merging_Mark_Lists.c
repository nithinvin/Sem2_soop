#include <stdio.h>

int main() {
    int n1, n2;
    int a[128], b[128], merged[256];
    int i = 0, j = 0, k = 0;

    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    /* Copy remaining elements */
    while (i < n1) {
        merged[k++] = a[i++];
    }

    while (j < n2) {
        merged[k++] = b[j++];
    }

    for (i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    for (i = k - 1; i >= 0; i--) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
