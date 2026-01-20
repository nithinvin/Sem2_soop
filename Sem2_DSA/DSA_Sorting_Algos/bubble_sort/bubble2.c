#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 1};
    int temp;

    printf("Before swap: %d %d\n", arr[0], arr[1]);

    if (arr[0] > arr[1]) {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }

    printf("After swap:  %d %d\n", arr[0], arr[1]);

    return 0;
}
