// C program to find the maximum number between two numbers using a pointer
#include <stdio.h>

int main() {
    int a, b;
    int *p1, *p2;

    printf("Input the first number : ");
    scanf("%d", &a);
    printf("Input the second number : ");
    scanf("%d", &b);

    p1 = &a;
    p2 = &b;

    if(*p1 > *p2)
        printf("%d is the maximum number.\n", *p1);
    else
        printf("%d is the maximum number.\n", *p2);

    return 0;
}
