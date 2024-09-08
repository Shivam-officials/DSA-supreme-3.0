#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/divide-two-integers/

int divideTwoNumber(int dividend, int divisor) {
    
    /** all the inputs will be int and we are using their abs values in calculation so if INT_MIN is there its abs value will go outside of int range and leads in bad calculation so the only thig which can make our quetiont go outside intrange is INT_MIN bcz int this range of values therefore so have to handle all the cases when the INT_MIN is involved as divident or divisor
     */

        // Case 1: If the dividend is INT_MIN and divisor is -1, the result overflows because
    // abs(INT_MIN) is greater than INT_MAX. Hence, return INT_MAX to prevent overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Case 2: If the dividend is INT_MIN and the divisor is 1, the result is simply INT_MIN
    // because dividing INT_MIN by 1 results in the same value, which is within the valid int range.
    if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }

    // Case 3: If the divisor is INT_MIN:
    // - If the dividend is also INT_MIN, the result should be 1 (since INT_MIN / INT_MIN = 1).
    // - If the dividend is any other number, the result should be 0 because INT_MIN is much larger
    //   in magnitude than any other int, and any number divided by such a large value results in 0.
    if (divisor == INT_MIN) {
        if (dividend == INT_MIN) {
            return 1;  // INT_MIN / INT_MIN = 1
        } else {
            return 0;  // Any other number divided by INT_MIN results in 0
        }
    }

    // General case: Division by zero is undefined, so return INT_MAX.
    if (divisor == 0) {
        return INT_MAX;
    }


    // Calculate the absolute values of dividend and divisor to avoid negative numbers during the division process.
    // This simplifies the division logic.
    int absDividend = abs(dividend);
    int absDivisor = abs(divisor);

    // Determine the sign of the result. If both numbers have the same sign, the result is positive.
    // If they have different signs, the result is negative.
    int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

    // Initialize quotient to store the result of the division.
    int quotient = 0;

    // The division process: Subtract multiples of the divisor from the dividend.
    // This is done using bit manipulation to efficiently handle large numbers.
    while (absDividend > 0 && absDividend >= absDivisor) {
        // Use long long for tempDivisor to avoid overflow when shifting.
        // This ensures that large values of absDivisor do not cause overflow when doubled.
        long long tempDivisor = absDivisor;
        int multiplyTimes = 1;

        // Shift tempDivisor left (multiply by 2) until it's just smaller than or equal to the dividend.
        // This optimizes the division by subtracting larger multiples of the divisor at once.
        while (absDividend > (tempDivisor << 1)) {
            tempDivisor <<= 1;  // Left shift the divisor to multiply by 2.
            multiplyTimes <<= 1; // Track how many times we multiplied the divisor by 2.
        }

        // Subtract the largest possible multiple of the divisor from the dividend.
        absDividend -= tempDivisor;

        // Add the corresponding multiple to the quotient.
        quotient += multiplyTimes;
    }

    // Apply the sign to the result.
    return quotient * sign;
}


int main() {

  cout << divideTwoNumber(-1010369383, -2147483648);

// int x = abs(-2147483648);
// cout << x;

  return 0;
}
