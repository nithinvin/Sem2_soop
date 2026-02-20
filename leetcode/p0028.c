/*
 * LeetCode 28 - Find the Index of the First Occurrence in a String
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <string.h>

int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    for (int i = 0; i <= hLen - nLen; i++) {
        if (strncmp(haystack + i, needle, nLen) == 0) {
            return i;
        }
    }
    return -1;
}
