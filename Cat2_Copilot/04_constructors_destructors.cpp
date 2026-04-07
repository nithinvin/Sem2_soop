/*
 * 04 - Constructors and Destructors
 *
 * CONSTRUCTOR — Special member function called AUTOMATICALLY when an object
 *   is created. Same name as the class, no return type.
 *   Types:
 *     1. Default constructor    — no parameters
 *     2. Parameterized          — takes arguments
 *     3. Copy constructor       — creates object from another object
 *
 * DESTRUCTOR — Called AUTOMATICALLY when an object goes out of scope or is
 *   deleted. Same name as class prefixed with ~. No parameters, no return
 *   type. Used for cleanup (freeing memory, closing files, etc.).
 *
 * Order: Constructors fire in creation order; destructors fire in REVERSE.
 */

#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    double price;

public:
    // 1. Default constructor
    Book() : title("Untitled"), price(0.0) {
        cout << "[Constructor] Default: " << title << endl;
    }

    // 2. Parameterized constructor
    Book(string t, double p) : title(t), price(p) {
        cout << "[Constructor] Param: " << title << endl;
    }

    // 3. Copy constructor
    Book(const Book& other) : title(other.title), price(other.price) {
        cout << "[Constructor] Copy: " << title << endl;
    }

    // Destructor
    ~Book() {
        cout << "[Destructor] " << title << endl;
    }

    void display() const {
        cout << "  Title: " << title << ", Price: $" << price << endl;
    }
};

int main() {
    cout << "--- Creating objects ---" << endl;

    Book b1;                       // calls default constructor
    // b1.title = "Harry Potter";
    Book b2("C++ Primer", 49.99);  // calls parameterized constructor
    Book b3 = b2;                  // calls copy constructor

    cout << "\n--- Displaying ---" << endl;
    b1.display();
    b2.display();
    b3.display();

    cout << "\n--- Scope demo ---" << endl;
    {
        Book b4("Temporary Book", 9.99);
        b4.display();
        cout << "  b4 going out of scope..." << endl;
    }  // b4 destructor called here
    b4.~Book();

    cout << "\n--- main() ending, remaining destructors fire in reverse ---" << endl;
    return 0;
    b3.~Book();
}
