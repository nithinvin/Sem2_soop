#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);   // Note the space before %c to skip whitespace

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
        printf("%c is an arithmetic operator\n", ch);
    } else {
        printf("%c is not an arithmetic operator\n", ch);
    }

    return 0;
}
