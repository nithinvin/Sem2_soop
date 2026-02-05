#include <stdio.h>

#define STACK_SIZE 20

int main() {
    int A[STACK_SIZE], B[STACK_SIZE];
    int topA = -1, topB = -1;

    int values[] = {2382, 2720, 4454, 3330, 3146, 615, 1013, 3850};
    int n = sizeof(values) / sizeof(values[0]);

    /* Load Stack A */
    for (int i = 0; i < n; i++) {
        A[++topA] = values[i];
    }

    /* Sort using Stack B */
    while (topA != -1) {
        int temp = A[topA--];   // POP from A

        while (topB != -1 && B[topB] < temp) {
            A[++topA] = B[topB--];   // POP B → PUSH A
        }

        B[++topB] = temp;  // PUSH into B
    }

    printf("Elements popped in ascending order:\n");
    while (topB != -1) {
        printf("%d\n", B[topB--]);
    }

    return 0;
}
