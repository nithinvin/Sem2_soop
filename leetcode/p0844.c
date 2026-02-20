/*
 * LeetCode 844 - Backspace String Compare
 *
 * Given two strings s and t, return true if they are equal
 * when both are typed into empty text editors.
 * '#' means a backspace character.
 *
 * O(1) space approach: traverse both strings from the end.
 */

#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;

    while (i >= 0 || j >= 0) {
        int skip;

        /* find next valid char in s */
        skip = 0;
        while (i >= 0) {
            if (s[i] == '#') { skip++; i--; }
            else if (skip > 0) { skip--; i--; }
            else break;
        }

        /* find next valid char in t */
        skip = 0;
        while (j >= 0) {
            if (t[j] == '#') { skip++; j--; }
            else if (skip > 0) { skip--; j--; }
            else break;
        }

        /* compare */
        if (i >= 0 && j >= 0) {
            if (s[i] != t[j]) return false;
        } else if (i >= 0 || j >= 0) {
            return false;
        }

        i--;
        j--;
    }

    return true;
}
