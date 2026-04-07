// LeetCode 70 - Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Approach: Dynamic programming (Fibonacci pattern), O(n) time, O(1) space.

#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1; // ways to reach step 1
    int prev1 = 2; // ways to reach step 2

    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(void) {
    printf("%d\n", climbStairs(2)); // Expected: 2
    printf("%d\n", climbStairs(3)); // Expected: 3
    printf("%d\n", climbStairs(5)); // Expected: 8
    printf("%d\n", climbStairs(10)); // Expected: 89

    return 0;
}
