#include <stdio.h>

int main() {
    int A[16], B[16];

    int initial[] = {8388, 1617, 303, 51277, 6486, 58177};
    int n = 6;

    int frontA = 0, rearA = -1;
    int frontB = 0, rearB = -1;
    int i;

    /* Load initial values into Queue A */
    for (i = 0; i < n; i++) {
        A[++rearA] = initial[i];
    }

    printf("Dequeuing elements in DESCENDING order:\n");

    while (frontA <= rearA) {

        /* Find maximum element in Queue A */
        int max = A[frontA];
        for (i = frontA + 1; i <= rearA; i++) {
            if (A[i] > max)
                max = A[i];
        }

        /* Move all elements except max from A to B */
        while (frontA <= rearA) {
            int x = A[frontA++];   // dequeue from A

            if (x != max) {
                B[++rearB] = x;   // enqueue into B
            }
        }

        printf("%d ", max);

        /* Move elements back from B to A */
        frontA = 0;
        rearA = -1;

        while (frontB <= rearB) {
            A[++rearA] = B[frontB++];
        }

        /* Reset Queue B */
        frontB = 0;
        rearB = -1;
    }
    printf("\n");

    return 0;
}
