#include <iostream>
using namespace std;

class Abc {
public:
    int x;   // An integer value
    int *y;  // A dynamically allocated integer pointer

    // Method to print the object details
    void print() {
        cout << "The object is at address: " << this << endl;
        printf(" x = %d \n y (address) = %p \n y (value at address) = %d \n\n", x, y, *y);
    }

    // Parameterized constructor to initialize x and dynamically allocate y
    Abc(int _x, int _y) : x(_x), y(new int(_y)) {}

  /**   // Default SHALLOW COPY constructor (commented out)
    //    This would copy both `x` and `y`, but the pointer `y` in the new object 
    //    would point to the same memory location as the original object. 
    //    This can cause issues like double free or unintended data modifications.
  */
    // Abc(const Abc &obj){
    //     x = obj.x;
    //     y = obj.y;
    //     cout << "Default shallow copy constructor\n";
    // }



 /**    // SMART COPY CTOR (DEEP COPY) explanation below
    //    Copies the value of `x` as usual.
    //    Dynamically allocates new memory for `y` and copies the value pointed by `obj.y`.
    //    This ensures that the new object has its own independent memory for `y`.
*/
    Abc(const Abc &obj) {
        x = obj.x;
        y = new int(*obj.y);
        cout << "Using the SMART COPY CTOR\n";
    }

    // Destructor to deallocate memory for `y`
    // 

    // Destructor to deallocate memory for y
    ~Abc() {
        delete y;  // Free the memory allocated to y
        cout << "Memory for y is deallocated for object at: " << this << endl;
    }
};

int main(int argc, char const *argv[]) {

// Uncomment and test different sections of the code to understand behavior

/**    // 1. Pointer Assignment and Double Free Error Example
    //    Here, both obj1 and obj2 will point to the same object. 
    //    Deleting obj1 makes obj2 a dangling pointer.
    //    Attempting to delete obj2 again would cause undefined behavior.
    //    On some systems, this could lead to a crash or a "double free" error.
*/


//    Abc *obj1 = new Abc(1, 2);
//    obj1->print();
//
//    Abc *obj2 = obj1; // obj2 now points to the same memory as obj1
//    delete obj1;      // Deletes the object, making obj2 a dangling pointer
//
//    obj2->print();    // Undefined behavior (accessing a dangling pointer)
//    delete obj2;      // Undefined behavior (attempting to free already-deallocated memory)

  /**   // 2. Shallow Copy Example
    //    Here, obj1 and obj2 share the same dynamically allocated memory for `y`.
    //    This demonstrates the issue with shallow copying: both objects point to the same memory.
    //    When one object's destructor is called, the shared memory is deleted,
    //    leaving the other object with a dangling pointer.
  */

//    Abc obj1(1, 2);
//    obj1.print();

//    Abc obj2 = obj1;  // Shallow copy: obj2 shares the same memory for `y` as obj1
//    obj2.print();     // Both objects have the same value for `y`'s pointer

 /**   // 3. Problem with Shallow Copy During Dynamic Allocation
    //    In this example, we create obj1 dynamically, then use shallow copying to create obj2.
    //    After deleting obj1, obj2's `y` becomes a dangling pointer, leading to undefined behavior.
    //    This highlights another issue with shallow copying when dynamic memory is involved.
 */

    // Abc *obj1 = new Abc(1, 2); // Dynamically create obj1
    // obj1->print();

    // Abc obj2 = *obj1;          // Shallow copy: obj2 shares the same memory for `y` as obj1
    // delete obj1;               // Deletes the object, leaving obj2's `y` as a dangling pointer

    // obj2.print();              // Undefined behavior: accessing dangling pointer


    
    /** Example 4: Deep Copy Demonstration
     *    - Dynamically create object `a` using the parameterized constructor.
     *    - Create object `b` by copying `a` using the copy constructor.
     *    - Modify the value pointed by `a->y` and verify that `b` retains its original value.
     *    - This demonstrates that each object has its own copy of dynamically allocated memory to work on them independently .
     *    - Finally, delete object `a` to clean up memory.
    */

    Abc *a = new Abc(1, 2); // Dynamically create object `a`
    a->print();             // Print details of object `a`

    Abc b = *a;             // Create a deep copy of `a` into `b`
    b.print();              // Print details of object `b`

    // Modify the value pointed by `a->y`
    *a->y = 21;
    cout << "After changing the first object's y pointer value\n" << endl;
    a->print();             // `a` reflects the updated value
    b.print();              // `b` retains its original value, proving deep copy

    delete a;               // Clean up dynamically allocated memory for `a`

    return 0;

    return 0;
}

