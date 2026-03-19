// LeetCode 11 - Container With Most Water
// Given n non-negative integers a[0], a[1], ..., a[n-1] where each represents
// a point at coordinate (i, a[i]). Find two lines that together with the x-axis
// forms a container that holds the most water.

#include <stdio.h>

int maxArea(int *height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxWater = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = h * (right - left);
        if (area > maxWater) maxWater = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main(void) {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("Max area: %d\n", maxArea(height, 9)); // Expected: 49
    return 0;
}
