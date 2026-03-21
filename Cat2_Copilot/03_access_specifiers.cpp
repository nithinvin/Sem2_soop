/*
 * 03 - Access Specifiers
 *
 * Control the visibility of class members:
 *
 * public    — Accessible from anywhere (inside class, derived class, outside).
 * private   — Accessible ONLY inside the class. This is the DEFAULT for class.
 * protected — Accessible inside the class AND in derived classes, but NOT
 *             from outside.
 *
 * Rule of thumb: keep data private, expose through public getters/setters.
 *
 *                  | Same class | Derived class | Outside |
 *  public          |    YES     |     YES       |   YES   |
 *  protected       |    YES     |     YES       |   NO    |
 *  private         |    YES     |     NO        |   NO    |
 */

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    double salary;       // only this class can touch salary directly

protected:
    string department;   // accessible in derived classes too

public:
    string name;         // accessible everywhere

    Employee(string n, string dept, double sal)
        : name(n), department(dept), salary(sal) {}

    // Public getter — controlled access to private data
    double getSalary() const { return salary; }

    void display() {
        cout << "Name: " << name
             << ", Dept: " << department
             << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, double sal)
        : Employee(n, "Management", sal) {}

    void showDept() {
        // ✅ Can access 'department' (protected) from derived class
        cout << name << " works in: " << department << endl;

        // ❌ Cannot access 'salary' (private) — would cause compile error:
        // cout << salary;
    }
};

int main() {
    Employee emp("Alice", "Engineering", 75000);
    emp.display();

    // ✅ public member — accessible outside
    cout << "Name: " << emp.name << endl;

    // ✅ public getter — safe way to read private data
    cout << "Salary via getter: " << emp.getSalary() << endl;

    // ❌ These would cause compile errors:
    // cout << emp.salary;      // private
    // cout << emp.department;  // protected

    cout << endl;
    Manager mgr("Bob", 95000);
    mgr.display();
    mgr.showDept();

    return 0;
}
