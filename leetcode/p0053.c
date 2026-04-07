// LeetCode 53 - Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum and return its sum.
// Approach: Kadane's algorithm, O(n) time, O(1) space.

#include <stdio.h>
#include <limits.h>

int maxSubArray(int *nums, int numsSize) {
    int maxSum = INT_MIN;
    int curr = 0;

    for (int i = 0; i < numsSize; i++) {
        curr += nums[i];
        if (curr > maxSum) maxSum = curr;
        if (curr < 0) curr = 0;
    }

    return maxSum;
}

int main(void) {
    int n1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSubArray(n1, 9)); // Expected: 6  [4,-1,2,1]

    int n2[] = {1};
    printf("%d\n", maxSubArray(n2, 1)); // Expected: 1

    int n3[] = {5, 4, -1, 7, 8};
    printf("%d\n", maxSubArray(n3, 5)); // Expected: 23

    return 0;
}
