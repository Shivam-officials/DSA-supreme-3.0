#include <iostream>
using namespace std;

// Note:
// If 'const' is to the left of '*', it indicates CONST DATA and a NON-CONST POINTER (e.g., const int *ptr).
// If 'const' is to the right of '*', it indicates a CONST POINTER and NON-CONST DATA (e.g., int *const ptr).


int main() {
  // const int x = 29;
  // // x = 5; /** const value modification is not allowed */
  // cout << x << endl;



  // Note: 1.const data with non pointer
  // const int *a = new int(2); // CONST DATA, NON-CONST POINTER // Dynamically
  // allocate memory for an integer
  // // int const* a = new int(2); // same like above line .. only the content
  // will be const not the pointer
  // // *a = 5;            // cannot change the value of the data at the current
  // address because it is const (read-only) cout << *a << endl; // Output: 2

  // // Note: Deleting 'a' only deallocates the dynamic memory it points to. The
  // pointer itself remains valid but will point to an invalid address (dangling
  // pointer). To avoid issues, reset the pointer to nullptr for safety.

  // delete a;          // Deallocate the memory to avoid memory leak
  // a = nullptr;       // Reset the pointer to null for safety

  // int b = 5;         // Declare a stack variable b
  // a = &b;            // The pointer can be reassigned to a new address even
  // if the data it points to is const cout << *a << endl; // Output: 5



  // note:2 const pointer with non-const data
//   int *const a = new int(2); // CONST POINTER, NON-CONST DATA
//   cout << *a << endl;        // Output: 2

//   *a = 5;             // Allowed: Data can be modified
//   cout << *a << endl; // Output: 5

//   int b = 10;
//   // a = &b; // Not allowed: Pointer itself is const, so it cannot point to
//   // another address

//   delete a; // Cleanup dynamic memory



    // note:3 const data const pointer
    const int *const c = new int(2); // CONST DATA, CONST POINTER
    cout << *c << endl;             // Output: 2

    // *c = 5; // Not allowed: Data is const, so it cannot be modified
    int d = 5;
    // c = &d; // Not allowed: Pointer is const, so it cannot be reassigned to another address

    delete c; // Cleanup dynamic memory


  return 0;
}
