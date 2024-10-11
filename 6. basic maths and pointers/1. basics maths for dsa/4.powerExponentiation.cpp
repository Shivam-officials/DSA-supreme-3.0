#include <iostream>
using namespace std;

// Intuition:
// This function efficiently calculates base^power using the method of exponentiation by squaring.
// - The idea is to reduce the number of multiplications by breaking the power into powers of 2.
// - Instead of multiplying the base power times, we repeatedly square the base and halve the power.
// - If the power is odd during any step, we multiply the result by the base before squaring.
// - This approach has a time complexity of O(log power), much faster than the naive O(power) method.


// Time Complexity = O(log n)
int fastExponentiationMethod_sir(int base, int power) {
    int ans = 1;  // Initialize the result as 1.

    // Loop while there is still power to process.
    while (power > 0) {
        // If the current power is odd, multiply the result by the base.
        if (power & 1) // Check if power is odd (using bitwise AND with 1).
        {
            ans *= base;  // Multiply the current result by the base.
        }
        base *= base;  // Square the base for the next iteration.
        power /= 2;    // Divide the power by 2 (equivalent to right-shift).
    }

    return ans;  // Return the final result.
}


// Time Complexity = O(n)
int naiveMethod(int base, int power) {
    int ans = base;  // Initialize result with the base value.

    // Loop to multiply the base by itself 'power - 1' times.
    for (int i = 1; i < power; i++) {
        ans = ans * base;  // Multiply the current result by the base.
    }

    return ans;  // Return the final result.
}


int main(int argc, char const *argv[]) {
    int power = 5,base = 2;
  cout << naiveMethod(2, 5) << endl;
  cout << fastExponentiationMethod_sir(2, 5)<<endl;
   
  return 0;
}
