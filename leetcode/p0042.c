// LeetCode 42 - Trapping Rain Water (Hard)
// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it can trap after raining.
// Approach: Two-pointer technique, O(n) time, O(1) space.

#include <stdio.h>

int trap(int *height, int heightSize) {
    if (heightSize < 3) return 0;

    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }

    return water;
}

int main(void) {
    int h1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(h1, 12)); // Expected: 6

    int h2[] = {4, 2, 0, 3, 2, 5};
    printf("%d\n", trap(h2, 6)); // Expected: 9

    return 0;
}
