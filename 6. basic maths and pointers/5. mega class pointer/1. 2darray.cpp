#include <iostream>
using namespace std;

// note: remember &x points to the whole array, whereas x points only to the base address (first element in 1D, first row in 2D)

int main(int argc, char const *argv[]) {
    int x[][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    // Printing the addresses of each element in the 2D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "x[" << i << "][" << j << "] -> " << &x[i][j] << " "; // Address of each element
        }
        cout << endl;
    }

    cout << "-------------------\n";

    int *n = &x[0][0];  // n points to the base address of the first element (x[0][0])
    // int (*n)[3][5] = &x;  // This works because n is a pointer to the entire array (3x5). incrementing this will give the adress of out of this matrix 
    int (*ptr)[5] = &x[0]; // ptr points to the first row of the 2D array (array of 5 integers)
    // int (*n)[5] = x;  // This also works since x can be treated as a pointer to an array of 5 integers
    // int *c = &x; // This does not work because &x points to the entire array, not just an int
    
    // Printing the base address of the first element
    cout << &x[0][0] << endl; // Output: Address of x[0][0] (base address)

    // Pointer arithmetic explanation
    cout << *(x + 2) + 1 << endl; // Address of x[2][1]. Here, (x + 2) points to the base address of the 3rd row (x[2])
                                  // Adding 1 to this gives the address of x[2][1]
    
    // Accessing the value at different locations
    cout << *(*(x + 2) + 1) << endl; // Output: 12. *(x + 2) gives the base address of the row x[2], 
                                     // adding 1 gives the address of x[2][1], dereferencing gives the value 12

    cout << *(*(x + 2)) + 5 << endl; // Output: 16. *(*(x + 2)) gives the value at x[2][0] (11), 
                                     // adding 5 results in 16

    cout << **(x + 1) << endl; // Output: 6. *(x + 1) points to the first element of the second row, 
                               // and dereferencing gives the value at x[1][0], which is 6

    cout << *(*(x) + 2) + 1 << endl; // Output: 4. *(x) gives the base address of x[0], 
                                     // adding 2 points to x[0][2] (3), and adding 1 gives 4

    cout << *(*(x + 1) + 3) << endl; // Output: 9. *(x + 1) gives the address of the row x[1], 
                                     // adding 3 points to x[1][3], which is 9

    cout << *n << endl; // Output: 1. n points to the base address of x[0][0], dereferencing it gives the value 1

    cout << *(n + 2) << endl; // Output: 3. n + 2 points to x[0][2], dereferencing gives the value 3

    cout << (*(n + 3) + 1) << endl; // Output: 5. n + 3 points to x[0][3] (4), adding 1 gives 5

    cout << *(n + 5) + 1 << endl; // Output: 7. n + 5 points to x[1][0] (6), adding 1 gives 7

    cout << ++*n << endl; // Output: 2. *n is initially 1, incrementing it changes the value to 2
    
    return 0;
}
