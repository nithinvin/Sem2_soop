#include <stdio.h>
#include <ctype.h>   // for tolower()
#include <string.h>  // for fgets()

int main() {
    char str[1024];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read input including spaces
    //scanf(" %[^\n]", str);  // reads until newline, including spaces

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    printf("Number of vowels = %d\n", count);

    return 0;
}
