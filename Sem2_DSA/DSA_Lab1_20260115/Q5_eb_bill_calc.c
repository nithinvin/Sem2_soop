#include <stdio.h>
#include <string.h>

int main() {
    int custID;
    char name[50];
    float units, chargePerUnit, totalAmount, surcharge = 0, netAmount;

    printf("Enter Customer ID: ");
    scanf("%d", &custID);
    printf("Enter Customer Name: ");
    scanf("%s", name);
    printf("Enter Units Consumed: ");
    scanf("%f", &units);

    // Apply Rate Slabs
    if (units < 200) {
        chargePerUnit = 1.20;
    } else if (units >= 200 && units < 400) {
        chargePerUnit = 1.50;
    } else if (units >= 400 && units < 600) {
        chargePerUnit = 1.80;
    } else {
        chargePerUnit = 2.00;
    }

    totalAmount = units * chargePerUnit;

    // Apply Surcharge if bill exceeds Rs. 400
    if (totalAmount > 400) {
        surcharge = totalAmount * 0.15;
    }

    netAmount = totalAmount + surcharge;

    // Ensure Minimum Bill of Rs. 100
    if (netAmount < 100) {
        netAmount = 100;
    }

    printf("\n--- Electricity Bill ---\n");
    printf("Customer ID    : %d\n", custID);
    printf("Customer Name  : %s\n", name);
    printf("Units Consumed : %.2f\n", units);
    printf("Amount Charges @Rs. %.2f per unit : %.2f\n", chargePerUnit, totalAmount);
    printf("Surcharge Amount : %.2f\n", surcharge);
    printf("Net Amount Paid by the Customer : %.2f\n", netAmount);

    return 0;
}
