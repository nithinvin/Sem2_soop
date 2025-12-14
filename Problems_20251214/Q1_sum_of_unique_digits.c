#include <stdio.h>

int main() {
    long long input_num;
    int freq[10] = {0};
    int digit, sum = 0;

    /* Read input */
    scanf("%lld", &input_num);

    /* Count frequency of each digit */
    while (input_num > 0) {
        digit = input_num % 10;
        freq[digit]++;
        input_num /= 10;
    }

    /* Sum digits that occur exactly once */
    for (int i = 0; i <= 9; i++) {
        if (freq[i] == 1) {
            sum += i;
        }
    }

    /* Output result */
    if (sum > 0) {
        printf("Sum of Unique Digits: %d\n", sum);
    } else {
        printf("No unique digits\n");
    }

    return 0;
}
