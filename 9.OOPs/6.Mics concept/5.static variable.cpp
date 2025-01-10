#include <iostream>
using namespace std;

// Class definition
class Abc {
    public:
    static int x, y; // Static variables shared across all objects of the class

    void print() {
        // Prints the values of static variables x and y
        cout << x << " " << y << endl;
    }
};

//note: Initialization of class k static variables (required for memory allocation)... Static members must be defined outside the class body (in global scope) for memory allocation.
int Abc::x;
int Abc::y;

int main(int argc, char const *argv[]) {
    // Create the first object of class Abc
    Abc Obj1;
    Obj1.x = 1; // Sets static variable x to 1 (shared)
    Obj1.y = 2; // Sets static variable y to 2 (shared)
    Obj1.print(); // Outputs: 1 2

    // Create the second object of class Abc
    Abc obj2;
    obj2.x = 11; // Changes static variable x to 11 (affects all objects)
    obj2.y = 21; // Changes static variable y to 21 (affects all objects)
    obj2.print(); // Outputs: 11 21

    // Print values using the first object again to show the shared behavior
    Obj1.print(); // Outputs: 11 21 (same as obj2, since x and y are shared)

    return 0;
}
