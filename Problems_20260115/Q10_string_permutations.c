// C program to print all permutations of a given string using pointers
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r) {
    int i;
    if (l == r) {
        printf("%s ", str);
    } else {
        for (i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i)); // backtrack
        }
    }
}

int main() {
    char str[128];
    printf("Input a string: ");
    scanf("%s", str);
    printf("The permutations of the string are :\n");
    permute(str, 0, strlen(str) - 1);
    printf("\n");
    return 0;
}
