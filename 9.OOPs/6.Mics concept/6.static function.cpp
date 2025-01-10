#include <iostream>
using namespace std;

// Class definition
class Abc {
    public:
    static int x, y; // Static variables: Shared across all objects of the class.
    int z = 44;      // Non-static variable: Each object will have its own copy of `z`.

    static void print() { 
        // Static function: Can only access static variables and static functions.
        cout << x << " " << y << endl; // Accessing static variables is allowed.
        // cout << z; // ERROR: Cannot access non-static variables inside a static function.
    }
};

// Note: Static variables must be defined outside the class for memory allocation.
int Abc::x; // Defines the static variable `x`.
int Abc::y; // Defines the static variable `y`.

int main(int argc, char const *argv[]) {
    // Create the first object of class Abc
    Abc Obj1;

    // Static variables belong to the class, not any instance.
    // Access them using the class name for better readability.
    Abc::x = 1; // Sets static variable `x` to 1.
    Abc::y = 2; // Sets static variable `y` to 2.

    // Call the static function using the class name.
    Abc::print(); // Outputs: 1 2

    // Modify static variables again.
    Abc::x = 11; // Updates static variable `x` to 11.
    Abc::y = 21; // Updates static variable `y` to 21.

    // Call the static function again to print updated values.
    Abc::print(); // Outputs: 11 21

    // Calling the static function using an object.
    // This is allowed, but not recommended for readability.
    Obj1.print(); // Outputs: 11 21
    // Note: Since `print` is static, the same function is called regardless of the object.

    return 0;
}
