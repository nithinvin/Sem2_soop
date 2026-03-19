// LeetCode 76 - Minimum Window Substring (Hard)
// Given two strings s and t, return the minimum window substring of s such that
// every character in t (including duplicates) is included in the window.
// Approach: Sliding window with character frequency counts, O(n) time.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char *minWindow(char *s, char *t) {
    int need[128] = {0};  // characters needed from t
    int have[128] = {0};  // characters in current window

    int tLen = strlen(t);
    int sLen = strlen(s);

    // Count required characters
    int required = 0; // number of unique chars in t
    for (int i = 0; i < tLen; i++) {
        if (need[(unsigned char)t[i]] == 0) required++;
        need[(unsigned char)t[i]]++;
    }

    int formed = 0; // unique chars in window that match required count
    int minLen = INT_MAX, minStart = 0;
    int left = 0;

    for (int right = 0; right < sLen; right++) {
        unsigned char c = s[right];
        have[c]++;

        if (need[c] > 0 && have[c] == need[c])
            formed++;

        // Try to shrink the window
        while (formed == required) {
            int windowLen = right - left + 1;
            if (windowLen < minLen) {
                minLen = windowLen;
                minStart = left;
            }

            unsigned char lc = s[left];
            have[lc]--;
            if (need[lc] > 0 && have[lc] < need[lc])
                formed--;
            left++;
        }
    }

    if (minLen == INT_MAX) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char *result = malloc(minLen + 1);
    memcpy(result, s + minStart, minLen);
    result[minLen] = '\0';
    return result;
}

int main(void) {
    char *r1 = minWindow("ADOBECODEBANC", "ABC");
    printf("\"%s\"\n", r1); // Expected: "BANC"
    free(r1);

    char *r2 = minWindow("a", "a");
    printf("\"%s\"\n", r2); // Expected: "a"
    free(r2);

    char *r3 = minWindow("a", "aa");
    printf("\"%s\"\n", r3); // Expected: ""
    free(r3);

    return 0;
}
