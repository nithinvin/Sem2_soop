// LeetCode 84 - Largest Rectangle in Histogram (Hard)
// Given an array of integers heights representing the histogram's bar heights
// where the width of each bar is 1, return the area of the largest rectangle.
// Approach: Monotonic stack, O(n) time, O(n) space.

#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int *heights, int heightsSize) {
    int *stack = malloc((heightsSize + 1) * sizeof(int)); // stack of indices
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        // Use 0 as sentinel for the final pop
        int curHeight = (i == heightsSize) ? 0 : heights[i];

        while (top >= 0 && curHeight < heights[stack[top]]) {
            int h = heights[stack[top--]];
            int width = (top >= 0) ? (i - stack[top] - 1) : i;
            int area = h * width;
            if (area > maxArea) maxArea = area;
        }
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

int main(void) {
    int h1[] = {2, 1, 5, 6, 2, 3};
    printf("%d\n", largestRectangleArea(h1, 6)); // Expected: 10

    int h2[] = {2, 4};
    printf("%d\n", largestRectangleArea(h2, 2)); // Expected: 4

    return 0;
}
