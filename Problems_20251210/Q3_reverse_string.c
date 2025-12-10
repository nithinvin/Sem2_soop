#include <stdio.h>

int main() {
    char str[128];
    int length = 0;

    printf("Enter a string: ");
    scanf("%127s", str);

    // Find length manually
    while (str[length] != '\0') {
        length++;
    }

    printf("Reversed string: ");

    // Print in reverse using a loop
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}
