// LeetCode 5 - Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.
// Approach: Expand around center for each character (and each pair),
// O(n^2) time, O(1) space.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Expand around center [left, right] and return length of longest palindrome
static int expandAroundCenter(const char *s, int left, int right, int len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}

char *longestPalindrome(char *s) {
    int len = strlen(s);
    if (len < 2) return s;

    int start = 0, maxLen = 1;

    for (int i = 0; i < len; i++) {
        // Odd-length palindromes (single center)
        int l1 = expandAroundCenter(s, i, i, len);
        // Even-length palindromes (pair center)
        int l2 = expandAroundCenter(s, i, i + 1, len);

        int best = l1 > l2 ? l1 : l2;
        if (best > maxLen) {
            maxLen = best;
            start = i - (best - 1) / 2;
        }
    }

    char *result = malloc(maxLen + 1);
    memcpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}

int main(void) {
    char *r1 = longestPalindrome("babad");
    printf("%s\n", r1); // Expected: "bab" or "aba"
    free(r1);

    char *r2 = longestPalindrome("cbbd");
    printf("%s\n", r2); // Expected: "bb"
    free(r2);

    char *r3 = longestPalindrome("racecar");
    printf("%s\n", r3); // Expected: "racecar"
    free(r3);

    char *r4 = longestPalindrome("a");
    printf("%s\n", r4); // Expected: "a"
    // r4 points into original string, not malloced for len<2

    return 0;
}
