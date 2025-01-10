#include <iostream>
using namespace std;

// Preprocessor Directives
// Macros are replaced by their values during preprocessing, before compilation.
// They help avoid repetitive code and improve readability.

// Define a constant value for PI
#define PI 3.14

// Define a macro for finding the maximum of two numbers
// Note: Macros are not type-safe and can behave unexpectedly with complex expressions.
#define MAXX(a, b) ((a) < (b) ? (b) : (a))

// Function to calculate the area of a circle
float area(float radius) {
    return PI * radius * radius;
}

int main(int argc, char const *argv[]) {
    // Demonstrate the use of the MAXX macro
    // MAXX(4, 5) evaluates to the larger of the two values, which is 5
    int c = MAXX(4, 5);
    cout << "Maximum of 4 and 5 is: " << c << endl;

    // Calculate the area of a circle with radius 1 using the area function
    cout << "Area of a circle with radius 1: " << area(1) << endl;

    return 0; // Indicate successful program execution
}
