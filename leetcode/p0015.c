// LeetCode 15 - 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, j != k, and nums[i] + nums[j] + nums[k] == 0.
// The solution set must not contain duplicate triplets.

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 256;
    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
        if (nums[i] > 0) break; // no way to sum to 0

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int *));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                result[*returnSize] = malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main(void) {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize;
    int *returnColumnSizes;

    int **res = threeSum(nums, 6, &returnSize, &returnColumnSizes);

    printf("Number of triplets: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", res[i][0], res[i][1], res[i][2]);
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);

    return 0;
}
