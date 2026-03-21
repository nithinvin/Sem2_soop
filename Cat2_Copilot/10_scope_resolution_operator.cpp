/*
 * 10 - Scope Resolution Operator (::)
 *
 * The :: operator specifies WHICH scope a name belongs to.
 *
 * Uses:
 *   1. Define member functions OUTSIDE the class body.
 *   2. Access a global variable when a local variable has the same name.
 *   3. Access static members of a class.
 *   4. Refer to members of a namespace.
 *   5. Refer to a specific base class member in multiple inheritance.
 */

#include <iostream>
#include <string>
using namespace std;

int value = 100;   // global variable

// --- Use 1: Define member functions outside the class ---
class Calculator {
    double result;
public:
    Calculator();                     // declared here
    void add(double x);              // declared here
    void show() const;               // declared here
    static string name();            // static member
};

// Defined OUTSIDE using ClassName::functionName
Calculator::Calculator() : result(0) {}

void Calculator::add(double x) {
    result += x;
}

void Calculator::show() const {
    cout << "Result = " << result << endl;
}

// --- Use 3: Static member access ---
string Calculator::name() {
    return "SimpleCalc";
}

// --- Use 4: Namespace ---
namespace Physics {
    double gravity = 9.81;
}

namespace Astro {
    double gravity = 1.62;   // Moon's gravity
}

// --- Use 5: Multiple inheritance disambiguation ---
class Base1 {
public:
    void greet() { cout << "Hello from Base1" << endl; }
};

class Base2 {
public:
    void greet() { cout << "Hello from Base2" << endl; }
};

class Derived : public Base1, public Base2 {
public:
    void greetAll() {
        Base1::greet();   // specify which base class
        Base2::greet();
    }
};

int main() {
    // Use 1: Member function defined outside
    Calculator calc;
    calc.add(10);
    calc.add(20);
    calc.show();

    // Use 2: Access global variable despite local shadow
    int value = 42;  // local variable shadows global
    cout << "Local value  = " << value << endl;
    cout << "Global value = " << ::value << endl;   // :: accesses global

    // Use 3: Static member access via class name
    cout << "Calculator name: " << Calculator::name() << endl;

    // Use 4: Namespace members
    cout << "Earth gravity: " << Physics::gravity << " m/s²" << endl;
    cout << "Moon gravity : " << Astro::gravity << " m/s²" << endl;

    // Use 5: Disambiguation in multiple inheritance
    Derived d;
    d.greetAll();

    return 0;
}
