/*
 * 08 - Inline Member Functions
 *
 * An INLINE function request tells the compiler to insert the function's
 * body directly at the call site (instead of a normal function call) to
 * eliminate call overhead. It's a hint — the compiler may ignore it.
 *
 * Two ways to make a member function inline:
 *   1. IMPLICITLY — Define the function INSIDE the class body.
 *   2. EXPLICITLY — Define it outside the class with the `inline` keyword.
 *
 * Best for: short, frequently-called functions (getters/setters).
 * Avoid for: large functions, recursive functions, functions with loops.
 */

#include <iostream>
using namespace std;

class Circle {
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Method 1: IMPLICITLY inline — defined inside the class
    double getRadius() const { return radius; }

    // These are declared here but defined outside
    double area() const;
    double circumference() const;
};

// Method 2: EXPLICITLY inline — defined outside with `inline` keyword
inline double Circle::area() const {
    return 3.14159 * radius * radius;
}

inline double Circle::circumference() const {
    return 2 * 3.14159 * radius;
}

// A regular (non-inline) function for comparison
double regularAdd(double a, double b) {
    return a + b;
}

// Explicit standalone inline function
inline double inlineAdd(double a, double b) {
    return a + b;
}

int main() {
    Circle c(5.0);

    // All these calls may be expanded inline by the compiler
    cout << "Radius       : " << c.getRadius() << endl;
    cout << "Area         : " << c.area() << endl;
    cout << "Circumference: " << c.circumference() << endl;

    cout << endl;
    cout << "regularAdd(3, 4) = " << regularAdd(3, 4) << endl;
    cout << "inlineAdd(3, 4)  = " << inlineAdd(3, 4) << endl;

    /*
     * Note: At runtime, you won't see any visible difference.
     * 'inline' is a compiler optimization hint that reduces function
     * call overhead for small functions. The actual inlining decision
     * is made by the compiler.
     */

    return 0;
}
