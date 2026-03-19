// LeetCode 739 - Daily Temperatures
// Given an array of integers temperatures representing daily temperatures,
// return an array answer such that answer[i] is the number of days you have
// to wait until a warmer temperature. If there is no future day, answer[i] = 0.
// Uses a monotonic stack approach.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 */
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize) {
    *returnSize = temperaturesSize;
    int *answer = calloc(temperaturesSize, sizeof(int));
    int *stack = malloc(temperaturesSize * sizeof(int)); // stack of indices
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            answer[idx] = i - idx;
        }
        stack[++top] = i;
    }

    free(stack);
    return answer;
}

int main(void) {
    int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int returnSize;

    int *res = dailyTemperatures(temps, 8, &returnSize);

    // Expected: [1, 1, 4, 2, 1, 1, 0, 0]
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", res[i], i < returnSize - 1 ? ", " : "");
    }
    printf("]\n");

    free(res);
    return 0;
}
