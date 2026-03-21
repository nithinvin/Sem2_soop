/*
 * 07 - Constant Member Functions
 *
 * A member function declared with `const` after its parameter list promises
 * NOT to modify any data member of the object.
 *
 *   ReturnType functionName() const;
 *
 * Key rules:
 *   - A const object can ONLY call const member functions.
 *   - A non-const object can call both const and non-const functions.
 *   - Inside a const function, `this` becomes `const ClassName* const this`.
 *   - If you MUST modify a member inside a const function, declare that
 *     member as `mutable`.
 */

#include <iostream>
#include <string>
using namespace std;

class Temperature {
    double celsius;
    mutable int readCount;   // can be modified even in const functions

public:
    Temperature(double c) : celsius(c), readCount(0) {}

    // const member function — does NOT modify the object
    double getCelsius() const {
        readCount++;          // allowed because 'mutable'
        return celsius;
    }

    // const member function — safe to call on const objects
    double toFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    // non-const member function — modifies the object
    void setCelsius(double c) {
        celsius = c;
    }

    int getReadCount() const { return readCount; }

    void display() const {
        cout << celsius << "°C = " << toFahrenheit() << "°F"
             << "  (read " << readCount << " times)" << endl;
    }
};

int main() {
    // Non-const object — can call everything
    Temperature t1(100.0);
    cout << "t1: " << t1.getCelsius() << "°C" << endl;
    t1.setCelsius(37.0);
    t1.display();

    cout << endl;

    // Const object — can ONLY call const member functions
    const Temperature t2(0.0);
    cout << "t2: " << t2.getCelsius() << "°C" << endl;
    cout << "t2 in Fahrenheit: " << t2.toFahrenheit() << endl;

    // t2.setCelsius(50.0);  // ❌ Error: cannot call non-const on const object

    // mutable member was still updated
    cout << "t2 read count: " << t2.getReadCount() << endl;

    return 0;
}
