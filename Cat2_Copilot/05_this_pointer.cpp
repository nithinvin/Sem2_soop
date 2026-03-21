/*
 * 05 - The `this` Pointer
 *
 * Every non-static member function has an implicit pointer called `this`
 * that points to the object on which the function was called.
 *
 * Uses:
 *   1. Disambiguate when parameter names shadow member names.
 *   2. Return *this to enable method chaining (fluent interface).
 *   3. Pass the current object to another function.
 *
 * `this` is a CONSTANT pointer:  ClassName* const this;
 *   — You can change what it points to's data, but not the pointer itself.
 */

#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;
public:
    // Use 1: Disambiguation — parameter 'x' shadows member 'x'
    Point(int x, int y) {
        this->x = x;   // this->x is the member, x is the parameter
        this->y = y;
    }

    // Use 2: Method chaining — return *this (the current object)
    Point& setX(int x) {
        this->x = x;
        return *this;   // return reference to current object
    }
    Point& setY(int y) {
        this->y = y;
        return *this;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Use 3: Comparing two objects
    bool isSameAs(const Point& other) const {
        // 'this' is the address of the current object
        return (this == &other);
    }
};

int main() {
    Point p1(3, 4);
    cout << "p1 = ";
    p1.display();

    // Method chaining using *this
    p1.setX(10).setY(20);   // each call returns *this, so we can chain
    cout << "After chaining: p1 = ";
    p1.display();

    // Comparing object identity
    Point p2(10, 20);
    cout << "p1 is same object as p2? " << (p1.isSameAs(p2) ? "Yes" : "No") << endl;
    cout << "p1 is same object as p1? " << (p1.isSameAs(p1) ? "Yes" : "No") << endl;

    return 0;
}
