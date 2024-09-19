#include <cmath>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <math.h>
// #include <iomanip>
using namespace std;

// Function to compute the integer square root of a number using binary search
// TC = O(log n)
int mySqrt(int number) {
  int start = 0;  // Start of binary search range
  int end = number / 2;  // End of binary search range (optimization: square root cannot be greater than number / 2)
  
  int mid;  // Middle value in the binary search range
  int ans;  // Variable to store the final answer

  while (start <= end) {
    mid = (start + end) >> 1;  // Find the middle element, (start + end) / 2 using bit shifting for efficiency

    if (mid <= number / mid) {  // Check if mid * mid is less than or equal to number (to avoid overflow)
      ans = mid;  // Update the answer to mid
      start = mid + 1;  // Move the start pointer to mid + 1 to find a larger candidate
    } else {
      end = mid - 1;  // If mid is too large, move the end pointer to mid - 1
    }
  }
  return ans;  // Return the integer part of the square root
}

// Function to compute the square root with a given precision using a brute force approach
// TC = O(log n) + O(precision)
double sqrtWithPrecision_bruteForce(int n, int precision) {
  double sqrt = mySqrt(n);  // First find the integer part of the square root (O(log n))

  double step = 0.1;  // Start with the smallest step for refining precision

  // Loop to refine the precision up to the given number of decimal places
  while (precision--)  // O(precision)
  {
    double j = sqrt;
    // Increment j by the current step value until j * j exceeds n
    while (j * j <= n) {
      sqrt = j;  // Update sqrt to the current value of j
      j += step;  // Move j by the current step size
    }
    step /= 10;  // Reduce the step size for the next decimal place
  }
  return sqrt;  // Return the square root with precision
}

// Function to compute the square root with precision using binary search
// More efficient approach compared to brute force
double sqrtWithPrecision_binarySearch(int n, int precision) {
  double differ = 1 / pow(10, precision);  // Precision threshold for stopping the binary search
   
  double start = 0;  // Start of binary search range
  double end = (double)n / 2;  // End of binary search range
  double mid;  // Midpoint of the binary search range
  double ans;  // Variable to store the answer
  
  // Perform binary search until the difference between start and end is smaller than the desired precision
  while (end - start >= differ) {  // Use (end - start >= differ) to avoid floating-point precision issues
    mid = (start + end) / 2;  // Calculate the midpoint
    double sq = mid * mid;  // Square of the mid value
    
    if (sq <= n) {  // If square of mid is less than or equal to n
      ans = mid;  // Update the answer to mid
      cout << "ans is " << ans << endl;
      start = mid;  // Narrow the search range to the upper half
    } else {
      end = mid;  // Narrow the search range to the lower half
    }
  }
  
/** 
* Note: Important Reminder
   * We use `end - start >= differ` instead of `start + differ <= end` because of floating-point precision issues.
   * In floating-point arithmetic, small values added to `start` may introduce rounding errors, causing the condition
   * `start + differ <= end` to behave unexpectedly. This could happen if `start + differ` becomes slightly greater
   * than `end` due to precision limitations, even when mathematically it should be smaller.
   * 
   * By using `end - start >= differ`, we directly compare the difference between `end` and `start`, which avoids
   * these precision errors. This method is more reliable for floating-point comparisons.
   */
  
  return ans;  // Return the square root with precision
}


/**
  * Note: cout print by defualt only 5 decimal values so either use printf from C  or setPrecision from iomanip without *fixed* it gives one less  decimal part by rounding off 
 */
int main() {
  int a = 63;  // Number for which we need to find the square root
  int ans = mySqrt(a);  // Compute the integer square root
  cout << fixed<< setprecision(14);
  // Compute the square root with precision using the brute force method
  double ansWithPrecision = sqrtWithPrecision_bruteForce(63, 14);
  printf("The value with brute force: %.14f \n", ansWithPrecision);
  
  // Compute the square root with precision using the binary search method
  double ansWithBinarySearch = sqrtWithPrecision_binarySearch(63, 14);
  // printf("The value with binary search: %.14f \n", ansWithBinarySearch);
  cout << ansWithBinarySearch;
  return 0;
}
