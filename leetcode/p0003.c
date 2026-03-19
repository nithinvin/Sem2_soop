// LeetCode 3 - Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastSeen[128]; // ASCII character index
    memset(lastSeen, -1, sizeof(lastSeen));

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];
        if (lastSeen[c] >= start) {
            start = lastSeen[c] + 1;
        }
        lastSeen[c] = i;
        int len = i - start + 1;
        if (len > maxLen) maxLen = len;
    }

    return maxLen;
}

int main(void) {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); // Expected: 3
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));    // Expected: 1
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));   // Expected: 3
    return 0;
}
