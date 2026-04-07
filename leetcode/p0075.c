// LeetCode 75 - Sort Colors
// Given an array nums with n objects colored red (0), white (1), or blue (2),
// sort them in-place so that objects of the same color are adjacent in the order 0, 1, 2.
// Approach: Dutch National Flag algorithm (3-way partition), O(n) time, O(1) space.

#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortColors(int *nums, int numsSize) {
    int low = 0;           // boundary for 0s (next position to place a 0)
    int mid = 0;           // current element
    int high = numsSize - 1; // boundary for 2s (next position to place a 2)

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(&nums[low], &nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(&nums[mid], &nums[high]);
            high--;
        }
    }
}

void printArray(int *nums, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d%s", nums[i], i < n - 1 ? ", " : "");
    }
    printf("]\n");
}

int main(void) {
    int n1[] = {2, 0, 2, 1, 1, 0};
    sortColors(n1, 6);
    printArray(n1, 6); // Expected: [0, 0, 1, 1, 2, 2]

    int n2[] = {2, 0, 1};
    sortColors(n2, 3);
    printArray(n2, 3); // Expected: [0, 1, 2]

    return 0;
}
