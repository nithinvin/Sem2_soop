/**
 * 1480. Running Sum of 1d Array
 *
 * Given an array nums, return the running sum where
 * runningSum[i] = sum(nums[0]...nums[i]).
 *
 * Note: Returned array must be malloced, set *returnSize.
 */

#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    result[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] + nums[i];
    }
    return result;
}
