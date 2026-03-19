// LeetCode 347 - Top K Frequent Elements
// Given an integer array nums and an integer k, return the k most frequent elements.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val;
    int freq;
} Pair;

int cmpFreq(const void *a, const void *b) {
    return ((Pair *)b)->freq - ((Pair *)a)->freq;
}

/**
 * Return an array of size *returnSize.
 */
int cmpInt(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize) {
    // Sort to group identical elements together
    int *sorted = malloc(numsSize * sizeof(int));
    memcpy(sorted, nums, numsSize * sizeof(int));
    qsort(sorted, numsSize, sizeof(int), cmpInt);

    // Count unique elements and their frequencies
    Pair *pairs = malloc(numsSize * sizeof(Pair));
    int pairCount = 0;
    int i = 0;
    while (i < numsSize) {
        int val = sorted[i];
        int count = 0;
        while (i < numsSize && sorted[i] == val) {
            count++;
            i++;
        }
        pairs[pairCount].val = val;
        pairs[pairCount].freq = count;
        pairCount++;
    }

    // Sort by frequency descending
    qsort(pairs, pairCount, sizeof(Pair), cmpFreq);

    *returnSize = k;
    int *result = malloc(k * sizeof(int));
    for (int j = 0; j < k; j++) {
        result[j] = pairs[j].val;
    }

    free(sorted);
    free(pairs);
    return result;
}

int main(void) {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int returnSize;

    int *res = topKFrequent(nums, 6, 2, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", res[i], i < returnSize - 1 ? ", " : "");
    }
    printf("]\n");

    free(res);
    return 0;
}
