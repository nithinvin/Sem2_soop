// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    for (int i = 0; strs[0][i] != '\0'; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != c || strs[j][i] == '\0') {
                char* prefix = (char*)malloc(i + 1);
                strncpy(prefix, strs[0], i);
                prefix[i] = '\0';
                return prefix;
            }
        }
    }

    return strs[0];
}

int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    printf("Output: \"%s\"\n", longestCommonPrefix(strs1, 3)); // "fl"

    char* strs2[] = {"dog", "racecar", "car"};
    printf("Output: \"%s\"\n", longestCommonPrefix(strs2, 3)); // ""

    return 0;
}
