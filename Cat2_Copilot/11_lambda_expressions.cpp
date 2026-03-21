/*
 * 11 - Lambda Expressions (C++11 and later)
 *
 * A lambda is an ANONYMOUS (unnamed) function object defined inline.
 *
 * Syntax:
 *   [capture](parameters) -> return_type { body }
 *
 * Capture clause []:
 *   []        — capture nothing
 *   [x]       — capture x by value (copy)
 *   [&x]      — capture x by reference
 *   [=]       — capture ALL local variables by value
 *   [&]       — capture ALL local variables by reference
 *   [=, &x]   — all by value, but x by reference
 *
 * Lambdas are great for:
 *   - Short callbacks / one-off functions
 *   - Passing to STL algorithms (sort, for_each, etc.)
 *   - Replacing small function objects (functors)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // --- Basic lambda ---
    auto greet = []() {
        cout << "Hello from a lambda!" << endl;
    };
    greet();   // call it like a regular function

    // --- Lambda with parameters ---
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    cout << "3 + 4 = " << add(3, 4) << endl;

    // --- Capture by value [=] ---
    int factor = 10;
    auto multiply = [factor](int x) {
        return x * factor;
        // factor++;  // ❌ Error: captured by value is const by default
    };
    cout << "5 * " << factor << " = " << multiply(5) << endl;

    // --- Capture by reference [&] ---
    int total = 0;
    auto accumulate = [&total](int x) {
        total += x;   // ✅ modifying the original variable
    };
    accumulate(10);
    accumulate(20);
    accumulate(30);
    cout << "Total = " << total << endl;   // 60

    // --- Mutable lambda (modify a by-value capture) ---
    int count = 0;
    auto counter = [count]() mutable {
        count++;   // modifies the lambda's internal copy, not original
        cout << "Lambda count = " << count << endl;
    };
    counter();   // 1
    counter();   // 2
    cout << "Original count = " << count << endl;  // still 0

    // --- Lambda with STL algorithms ---
    vector<int> nums = {5, 2, 8, 1, 9, 3};

    // Sort descending using lambda as comparator
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    cout << "Sorted descending: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    // for_each with lambda
    cout << "Doubled: ";
    for_each(nums.begin(), nums.end(), [](int n) {
        cout << n * 2 << " ";
    });
    cout << endl;

    // --- Immediately Invoked Lambda Expression (IILE) ---
    int result = [](int a, int b) { return a * b; }(6, 7);
    cout << "6 * 7 = " << result << endl;

    return 0;
}
