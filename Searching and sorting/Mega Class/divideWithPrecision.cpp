#include <cmath>    // For mathematical operations like pow()
#include <cstdlib>  // For abs() function
#include <iomanip>  // For controlling the precision of floating-point output
#include <iostream> // For input-output operations
#include <vector>   // (Unused in this program)

using namespace std;

// Function to perform division using Binary Search with precision
double divideWithPrecision_BinarySearch(int dividend, int divisor, int precision) {
  // Determine the sign of the result
  int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

  // Calculate the smallest difference allowed based on precision
  double differ = 1 / pow(10, precision); 
  
  // Get absolute values of dividend and divisor
  int absDivident = abs(dividend);
  int absDivisor = abs(divisor);
  
  // Binary search setup: start from 0 to absolute dividend
  double start = 0;
  double end = (double)absDivident;
  double mid;
  double ans;

  // Binary search loop until the difference between start and end is within precision tolerance
  while (end - start >= differ) {
    mid = (start + end) / 2;  // Find the mid-point of start and end

    // Check if mid * divisor is less than or equal to dividend
    if (mid * divisor <= dividend) {
      ans = mid;        // Update the answer
      start = mid;      // Move start point to mid
    } else {
      end = mid;        // Move end point to mid
    }
  }
  
  // Debug statement to print the current answer
  cout << "ans is the fucking" << ans << endl;

  // Return the result with the correct sign
  return ans * sign;
}

// Function to perform division with precision using linear search method
double divide(int dividend, int divisor, int precision) {
  // Determine the sign of the result
  int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

  // Get absolute values of dividend and divisor
  int absDivident = abs(dividend);
  int absDivisor = abs(divisor);
  
  // Find base answer using integer division (simulating binary search)
  int baseAns = absDivident / absDivisor; // Integer division for base value
  
  // Initialize step-wise precision search
  double start = baseAns;
  double step = 0.1;  // Start with a step size of 0.1

  // Loop to refine the answer based on precision required
  while (precision--) {
    double j = start + step;  // Increment start by step
    // Loop to find the closest multiple of the divisor that fits in dividend
    while (j * absDivisor <= absDivident) {
      start = j;  // Update start to the new value
      j += step;  // Increment by the current step size
      
      // Debug statement to print the current start value
      cout << "start is now " << start << endl;
    }
    
    step /= 10;  // Reduce the step size for finer precision
  }

  // Return the result with the correct sign
  return start * sign;
}

int main() {
  int dividend = 68;
  int divisor = 7;
  int precision = 8;

  // Set the precision for the output
  cout << fixed << setprecision(precision);

// Uncomment the below line to test the linear search method
//   cout << divide(dividend, divisor, precision) << endl;

  // Call the binary search method with precision and print the result
  cout << divideWithPrecision_BinarySearch(68, 7, precision);

  return 0;
}
