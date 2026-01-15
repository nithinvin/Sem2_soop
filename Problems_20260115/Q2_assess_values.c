#include <stdio.h>

int main() {
    int p, q, r, s;
    int valid = 1;

    printf("Input the first integer: ");
    scanf("%d", &p);
    printf("Input the second integer: ");
    scanf("%d", &q);
    printf("Input the third integer: ");
    scanf("%d", &r);
    printf("Input the fourth integer: ");
    scanf("%d", &s);

    // Check if p is even
    if (p % 2 != 0) {
        valid = 0;
    }
    // Check if q, r, s are positive
    if (q <= 0 || r <= 0 || s <= 0) {
        valid = 0;
    }
    // Check the main conditions
    if (q <= r || s <= p || (r + s) <= (p + q)) {
        valid = 0;
    }

    if (valid) {
        printf("Correct values\n");
    } else {
        printf("Wrong values\n");
    }

    return 0;
}