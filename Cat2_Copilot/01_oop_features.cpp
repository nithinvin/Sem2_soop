/*
 * 01 - Features of Object-Oriented Programming
 *
 * OOP is built on four pillars:
 *
 * 1. ENCAPSULATION  — Bundling data (variables) and methods (functions) that
 *    operate on that data into a single unit (class). Internal details are
 *    hidden; only a controlled interface is exposed.
 *
 * 2. ABSTRACTION    — Showing only essential features while hiding complexity.
 *    Users interact through a simple interface without knowing how it works
 *    internally.
 *
 * 3. INHERITANCE    — A new class (derived) can reuse and extend the
 *    properties & behavior of an existing class (base). Promotes code reuse.
 *
 * 4. POLYMORPHISM   — "Many forms." The same function name behaves differently
 *    depending on the object that calls it.
 *      • Compile-time (function/operator overloading)
 *      • Run-time    (virtual functions / overriding)
 */

#include <iostream>
#include <string>
using namespace std;

// --- ENCAPSULATION ---
class BankAccount {
    double balance;  // private by default — hidden from outside
public:
    BankAccount(double b) {
        balance = b;
    }
    void deposit(double amt) { 
        balance += amt; 
    }
    double getBalance() const { 
        return balance; 
    }  // controlled access
    ~BackAccount() {}
};

// --- ABSTRACTION ---
class Shape {
public:
    virtual double area() const = 0;   // pure virtual — "what" not "how"
    virtual ~Shape() {}
};

// --- INHERITANCE ---
class Circle : public Shape {          // Circle IS-A Shape
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {       // Rectangle IS-A Shape
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }
};

// --- POLYMORPHISM ---
void printArea(const Shape& s) {       // same function, different behavior
    cout << "Area = " << s.area() << endl;
}

int main() {
    // Encapsulation
    BankAccount acc(1000);
    acc.deposit(500);
    cout << "Balance: " << acc.getBalance() << endl;

    //Shape s;

    // Inheritance + Polymorphism
    Circle c(5);
    Rectangle r(4, 6);

    printArea(c);   // calls Circle::area()
    printArea(r);   // calls Rectangle::area()

    return 0;
}
