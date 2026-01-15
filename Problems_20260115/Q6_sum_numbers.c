#include <stdio.h>

int main() {
    int num;
    int sum = 0;

    printf("Enter integers (enter 0 to stop):\n");

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        if (num > 0) {
            sum += num;
        }

        printf("Enter a number: ");
        scanf("%d", &num);
    }

    printf("\nThe sum of all positive integers entered is: %d\n", sum);

    return 0;
}
