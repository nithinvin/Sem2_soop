// LeetCode 287 - Find the Duplicate Number
// Given an array nums containing n+1 integers in range [1, n], find the
// duplicate number. Must not modify the array, must use O(1) extra space.
// Approach: Floyd's cycle detection (tortoise and hare) treating the array
// as a linked list where nums[i] points to index nums[i], O(n) time, O(1) space.

#include <stdio.h>

int findDuplicate(int *nums, int numsSize) {
    (void)numsSize; // n+1 elements in range [1,n]; size not needed for Floyd's algorithm
    // Phase 1: Find intersection point inside the cycle
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the entry point of the cycle (the duplicate)
    int ptr = nums[0];
    while (ptr != slow) {
        ptr = nums[ptr];
        slow = nums[slow];
    }

    return slow;
}

int main(void) {
    int n1[] = {1, 3, 4, 2, 2};
    printf("%d\n", findDuplicate(n1, 5)); // Expected: 2

    int n2[] = {3, 1, 3, 4, 2};
    printf("%d\n", findDuplicate(n2, 5)); // Expected: 3

    int n3[] = {3, 3, 3, 3, 3};
    printf("%d\n", findDuplicate(n3, 5)); // Expected: 3

    return 0;
}
