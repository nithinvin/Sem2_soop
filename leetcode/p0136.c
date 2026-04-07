// LeetCode 136 - Single Number
// Given a non-empty array of integers nums where every element appears twice
// except for one, find that single one.
// Approach: XOR all elements — pairs cancel out, leaving the unique one.
// O(n) time, O(1) space.

#include <stdio.h>

int singleNumber(int *nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main(void) {
    int n1[] = {2, 2, 1};
    printf("%d\n", singleNumber(n1, 3)); // Expected: 1

    int n2[] = {4, 1, 2, 1, 2};
    printf("%d\n", singleNumber(n2, 5)); // Expected: 4

    int n3[] = {1};
    printf("%d\n", singleNumber(n3, 1)); // Expected: 1

    return 0;
}
