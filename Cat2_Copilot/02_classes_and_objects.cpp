/*
 * 02 - Classes and Objects
 *
 * CLASS  — A user-defined blueprint/template that defines data members
 *          (attributes) and member functions (methods).
 *
 * OBJECT — An instance of a class. Each object gets its own copy of the
 *          data members but shares the member function code.
 *
 * Syntax:
 *   class ClassName {
 *       // data members
 *       // member functions
 *   };
 *
 *   ClassName obj;          // creating an object
 *   obj.memberFunction();   // accessing through object
 */

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float marks;

    void display() {
        cout << "Name   : " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks  : " << marks << endl;
    }

    bool hasPassed() {
        return marks >= 40.0f;
    }
};

int main() {
    // Creating objects
    Student s1, s2;

    // Setting data for s1
    s1.name   = "Alice";
    s1.rollNo = 101;
    s1.marks  = 85.5;

    // Setting data for s2
    s2.name   = "Bob";
    s2.rollNo = 102;
    s2.marks  = 35.0;

    // Using member functions
    cout << "--- Student 1 ---" << endl;
    s1.display();
    cout << "Passed: " << (s1.hasPassed() ? "Yes" : "No") << endl;

    cout << "\n--- Student 2 ---" << endl;
    s2.display();
    cout << "Passed: " << (s2.hasPassed() ? "Yes" : "No") << endl;

    // Objects are independent — changing s1 doesn't affect s2
    s1.marks = 90.0;
    cout << "\nAfter changing s1 marks to 90:" << endl;
    cout << "s1 marks = " << s1.marks << endl;
    cout << "s2 marks = " << s2.marks << " (unchanged)" << endl;

    return 0;
}
