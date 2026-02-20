/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    int left = 0, right = numsSize - 1;
    int pos = numsSize - 1;

    while (left <= right) {
        int lsq = nums[left] * nums[left];
        int rsq = nums[right] * nums[right];
        if (lsq > rsq) {
            result[pos--] = lsq;
            left++;
        } else {
            result[pos--] = rsq;
            right--;
        }
    }

    return result;
}
