/*
 * 06 - Static Data Members, Static Member Functions, and Static Objects
 *
 * STATIC DATA MEMBER:
 *   - Shared by ALL objects of the class (one copy in memory).
 *   - Must be defined/initialized outside the class.
 *   - Exists even if no objects are created.
 *
 * STATIC MEMBER FUNCTION:
 *   - Can be called without an object: ClassName::function()
 *   - Can ONLY access static data members (no `this` pointer).
 *
 * STATIC OBJECT:
 *   - A local object declared static inside a function persists across
 *     calls and is destroyed only when the program ends.
 */

#include <iostream>
using namespace std;

class Counter {
    int id;
    static int count;   // shared across all objects

public:
    Counter() {
        count++;
        id = count;
        cout << "  Object #" << id << " created (total: " << count << ")" << endl;
    }

    ~Counter() {
        cout << "  Object #" << id << " destroyed (total before: " << count << ")" << endl;
        count--;
    }

    // Static member function — can access only static members
    static int getCount() {
        // return id;  // ❌ Error: can't access non-static 'id'
        return count;
    }
};

// Define static member OUTSIDE the class
int Counter::count = 0;

// --- Static Object Demo ---
void demoStaticObject() {
    cout << "  Entering demoStaticObject()..." << endl;
    static Counter localStatic;    // created once, survives across calls
    cout << "  Leaving demoStaticObject()..." << endl;
}

int main() {
    // Static member function called without any object
    cout << "Count before any object: " << Counter::getCount() << endl;

    cout << "\n--- Creating objects ---" << endl;
    Counter c1;
    Counter c2;
    Counter c3;
    cout << "Count now: " << Counter::getCount() << endl;

    cout << "\n--- Static object demo ---" << endl;
    demoStaticObject();   // static object created on first call
    demoStaticObject();   // NOT created again on second call

    cout << "\n--- main() ending ---" << endl;
    // c3, c2, c1 destroyed here; static object destroyed last
    return 0;
}
