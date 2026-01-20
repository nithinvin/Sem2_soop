#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 1};

    printf("Comparing %d and %d\n", arr[0], arr[1]);

    if (arr[0] > arr[1]) {
        printf("First is bigger\n");
    } else {
        printf("First is smaller or equal\n");
    }

    return 0;
}
