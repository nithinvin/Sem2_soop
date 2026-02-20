// 344. Reverse String
// Write a function that reverses a string. The input string is given as an
// array of characters s. You must do this by modifying the input array in-place
// with O(1) extra memory.

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}
