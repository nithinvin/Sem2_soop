#include <stdio.h>
#include <ctype.h>

int main() {
    char str[128];
    int alphabets = 0, digits = 0;
    int i;

    printf("Enter a string: ");
    scanf("%127s", str);  // reads a word (no spaces)

    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            alphabets++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }

    printf("Alphabets = %d\n", alphabets);
    printf("Digits = %d\n", digits);

    return 0;
}
