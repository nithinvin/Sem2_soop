#include <stdio.h>

void printArraySegment(int arr[], int left, int right) {
    printf("[");
    for (int i = left; i <= right; i++) {
        printf("%d", arr[i]);
        if (i < right) printf(", ");
    }
    printf("]");
}

void merge(int arr[], int left, int mid, int right, int level) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    printf("\nLevel %d - MERGE\n", level);
    printf("Left Part  : ");
    printArraySegment(L, 0, n1 - 1);
    printf("\nRight Part : ");
    printArraySegment(R, 0, n2 - 1);
    printf("\n");

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        printf("Compare %d and %d -> ", L[i], R[j]);
        if (L[i] <= R[j]) {
            printf("Take %d\n", L[i]);
            arr[k++] = L[i++];
        } else {
            printf("Take %d\n", R[j]);
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        printf("Take remaining %d\n", L[i]);
        arr[k++] = L[i++];
    }

    while (j < n2) {
        printf("Take remaining %d\n", R[j]);
        arr[k++] = R[j++];
    }

    printf("After Merge: ");
    printArraySegment(arr, left, right);
    printf("\n");
}

void mergeSort(int arr[], int left, int right, int level) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        printf("\nLevel %d - SPLIT ", level);
        printArraySegment(arr, left, right);
        printf("\n");

        mergeSort(arr, left, mid, level + 1);
        mergeSort(arr, mid + 1, right, level + 1);

        merge(arr, left, mid, right, level);
    }
}

int main() {
    int arr[] = {7, 4, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArraySegment(arr, 0, n - 1);
    printf("\n");

    mergeSort(arr, 0, n - 1, 0);

    printf("\nFinal Sorted Array: ");
    printArraySegment(arr, 0, n - 1);
    printf("\n");

    return 0;
}
