#include <stdio.h>

int main() {
    int roll_no, phy, chem, comp, total;
    char name[50];
    float percentage;
    char division[10];

    printf("Input the Roll Number of the student: ");
    scanf("%d", &roll_no);
    printf("Input the Name of the Student: ");
    scanf("%s", name);
    printf("Input the marks of Physics, Chemistry and Computer Application: ");
    scanf("%d %d %d", &phy, &chem, &comp);

    total = phy + chem + comp;
    percentage = total / 3.0f;

    printf("Roll No: %d\n", roll_no);
    printf("Name of Student: %s\n", name);
    printf("Marks in Physics: %d\n", phy);
    printf("Marks in Chemistry: %d\n", chem);
    printf("Marks in Computer Application: %d\n", comp);
    printf("Total Marks = %d\n", total);
    printf("Percentage = %.2f\n", percentage);
    printf("Division = ");

    if (percentage >= 60)
        printf("First");
    else if (percentage >= 48)
        printf("Second");
    else if (percentage >= 36)
        printf("Pass");
    else
        printf("Fail");

    printf("\n");

    return 0;
}
