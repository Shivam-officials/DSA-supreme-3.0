//greatest common divisor 
#include <iostream>
using namespace std;

// note: u can also find the LCM of number through GCD bcz LCM == product(a,b) / GCD(a,b)

/**
 * @explanation:
  * Function to compute the Greatest Common Divisor (GCD) of two integers 'a' and 'b'.
  * This implementation uses the subtraction method to find the GCD.
  * The algorithm works by repeatedly subtracting the smaller number from the larger one
  * until one of the numbers becomes zero. The non-zero number at that point is the GCD.
  * This method is based on the property: GCD(a, b) = GCD(b, a - b).
  * Note: This method is not the most efficient in terms of TC; for better TC performance, consider using
  * the Euclidean algorithm which utilizes the modulus operation.
  * bt the modulous method uses the Modulous which is heavy operation so avoid it although it works same use replace % with - sign 
 */


// TC = O(log(max(a,b)))
int gcd(int a, int b) {
    // Base cases: if one number is 0, return the other number as GCD.
    if (a == 0) return b; // If 'a' is 0, the GCD is 'b'.
    if (b == 0) return a; // If 'b' is 0, the GCD is 'a'.

    // Main loop to find the GCD using the subtraction method.
    while (a > 0 && b > 0) {
        // If 'a' is greater than 'b', subtract 'b' from 'a'.
        if (a > b) {
            a = a - b; // Reduce 'a' by 'b'.
        } else {
            b = b - a; // Reduce 'b' by 'a'.
        }
    }

    // When the loop ends, one of the numbers is zero.
    // Return the non-zero number, which is the GCD.
    return a == 0 ? b : a; // If 'a' is 0, return 'b', else return 'a'.
}


int main(int argc, char const *argv[])
{
    cout << gcd(36, 24);
    return 0;
}
