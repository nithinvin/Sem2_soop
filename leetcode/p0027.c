int removeElement(int* nums, int numsSize, int val) {
	int writeIndex = 0;

	for (int readIndex = 0; readIndex < numsSize; readIndex++) {
		if (nums[readIndex] != val) {
			nums[writeIndex] = nums[readIndex];
			writeIndex++;
		}
	}

	return writeIndex;
}
