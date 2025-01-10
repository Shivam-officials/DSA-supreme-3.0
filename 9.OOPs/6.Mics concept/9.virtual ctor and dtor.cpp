#include <iostream>
using namespace std;

// Base class definition
class Base {
public:
    // Constructor of Base class
    Base() {
        cout << "Base class constructor\n";
    }

    // Virtual destructor of Base class //note: hmesha inheritance hai to base class destructor virtual hi bnao
    // Reason: To ensure proper cleanup of derived class objects when the base class pointer is used for deletion.
    virtual ~Base() {
        cout << "Base class destructor\n";
    }
};

// Derived class inheriting from Base
class Derived : public Base {
public:
    int *a; // Pointer to dynamically allocated memory

    // Constructor of Derived class
    Derived() {
        a = new int[100]; // Allocating memory
        cout << "Derived class constructor\n";
    }

    // Destructor of Derived class
    ~Derived() {
        delete[] a; // Releasing allocated memory
        cout << "Derived class destructor\n";
    }
};

int main(int argc, char const *argv[]) {
    
    /* Case 1: Object instantiation on the stack
        Uncommenting the following lines creates stack-based objects.
        Both constructors and destructors will be called in the correct order:
        1. Base class constructor
        2. Derived class constructor
        3. Derived class destructor
        4. Base class destructor
    */
    // Base bs;
    // Derived dv;

    /* Case 2: Polymorphic behavior with Base pointer pointing to Derived object
        This demonstrates the importance of a virtual destructor in the Base class.
        If the destructor in Base is not virtual, only the Base class destructor is called,
        leading to memory leaks as Derived class destructor is never invoked.
    */
    Base *dv = new Derived(); // Base pointer pointing to Derived object // UPCASTING
    delete dv; // Proper destruction due to virtual destructor

    return 0;
}
