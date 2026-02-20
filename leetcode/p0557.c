/*
 * LeetCode 557 - Reverse Words in a String III
 *
 * Given a string s, reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order.
 *
 * Example 1: "Let's take LeetCode contest" -> "s'teL ekat edoCteeL tsetnoc"
 * Example 2: "Mr Ding"                     -> "rM gniD"
 */

#include <string.h>

static void reverse(char *s, int left, int right) {
    while (left < right) {
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}

char *reverseWords(char *s) {
    int n = strlen(s);
    int start = 0;

    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}
