/*
 * 09 - Friend Functions and Friend Classes
 *
 * FRIEND FUNCTION:
 *   A non-member function that is granted access to a class's private and
 *   protected members. Declared inside the class with the `friend` keyword.
 *   - It is NOT a member of the class (no `this` pointer).
 *   - It cannot be called using an object with dot operator.
 *   - Useful for operator overloading and functions that need to access
 *     private data of two different classes.
 *
 * FRIEND CLASS:
 *   If class B is declared a friend of class A, then ALL member functions
 *   of B can access A's private and protected members.
 *   - Friendship is NOT mutual (A can't access B's privates unless B also
 *     declares A as friend).
 *   - Friendship is NOT inherited.
 */

#include <iostream>
using namespace std;

// --- FRIEND FUNCTION DEMO ---
class Box {
    double length, width;

public:
    Box(double l, double w) : length(l), width(w) {}

    // Declare a friend function — it can access private members
    friend double computeArea(const Box& b);

    // Declare a friend class
    friend class BoxPrinter;
};

// Friend function definition (NOT a member — no Box:: prefix)
double computeArea(const Box& b) {
    return b.length * b.width;   // ✅ accessing private members directly
}

// --- FRIEND CLASS DEMO ---
class BoxPrinter {
public:
    void print(const Box& b) {
        // ✅ Can access Box's private members because BoxPrinter is a friend
        cout << "Box [" << b.length << " x " << b.width << "]"
             << " Area = " << b.length * b.width << endl;
    }
};

// --- FRIEND FUNCTION WITH TWO CLASSES ---
class Celsius;  // forward declaration

class Fahrenheit {
    double temp;
public:
    Fahrenheit(double t) : temp(t) {}
    friend void compare(const Celsius& c, const Fahrenheit& f);
};

class Celsius {
    double temp;
public:
    Celsius(double t) : temp(t) {}
    friend void compare(const Celsius& c, const Fahrenheit& f);
};

// This function accesses private members of BOTH classes
void compare(const Celsius& c, const Fahrenheit& f) {
    double celsiusAsF = (c.temp * 9.0 / 5.0) + 32.0;
    cout << c.temp << "°C = " << celsiusAsF << "°F vs " << f.temp << "°F => ";
    if (celsiusAsF > f.temp)
        cout << "Celsius value is hotter" << endl;
    else if (celsiusAsF < f.temp)
        cout << "Fahrenheit value is hotter" << endl;
    else
        cout << "Both are equal" << endl;
}

int main() {
    // Friend function
    Box b(5.0, 3.0);
    cout << "Area (via friend function): " << computeArea(b) << endl;

    // Friend class
    BoxPrinter printer;
    printer.print(b);

    cout << endl;

    // Friend function accessing two classes
    Celsius c(100);
    Fahrenheit f(200);
    compare(c, f);

    return 0;
}
