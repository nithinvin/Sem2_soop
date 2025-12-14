#include <stdio.h>

int factorial(int d)
{
    int fact = 1;
    for (int i = 1; i <= d; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int input_num, temp, digit;
    int sum = 0;

    scanf("%d", &input_num);

    temp = input_num;

    while (temp > 0)
    {
        digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    if (sum == input_num)
        printf("Strong Number\n");
    else
        printf("Not a Strong Number\n");

    return 0;
}

