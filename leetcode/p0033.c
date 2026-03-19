// LeetCode 33 - Search in Rotated Sorted Array
// Given a rotated sorted array and a target, return the index of target or -1.
// You must write an algorithm with O(log n) runtime complexity.

#include <stdio.h>

int search(int *nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main(void) {
    int nums1[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(nums1, 7, 0)); // Expected: 4

    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(nums2, 7, 3)); // Expected: -1

    int nums3[] = {1};
    printf("%d\n", search(nums3, 1, 0)); // Expected: -1
    return 0;
}
