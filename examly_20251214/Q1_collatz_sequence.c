#include <stdio.h>

int collatz_next(int n) {
    if (n % 2 == 0) {
        // Rule 1: Even number
        return n / 2;
    } else {
        // Rule 2: Odd number
        return 3 * n + 1;
    }
}

int main() {
    int n_input;
    int current_number;
    int length = 0;

    printf("Enter the starting integer (n): ");
    
    // Using %d for input as the problem statement implies an integer 'n'
    if (scanf("%d", &n_input) != 1 || n_input <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Exit with an error code
    }

    current_number = n_input;

    // Loop until the sequence reaches 1
    while (current_number != 1) {
        // Print the current number and a space
        printf("%lld ", current_number);
        
        // Calculate the next number and update the current number
        current_number = collatz_next(current_number);
        
        // Increment the length counter
        length++;
    }

    // Print the final number (1) and a newline
    printf("1\n");
    
    // Add 1 to the length to account for the final number '1'
    length++;

    // --- Output Format: Second line (The length) ---
    printf("The length of the sequence is %d\n", length);

    return 0; // Exit successfully
}
