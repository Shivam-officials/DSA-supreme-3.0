//
// Created by shivam on 22-07-2024.
//
#include<iostream>
#include <vector>
using namespace std;



int binarySearch(vector<int> v, int start, int end, int target) {
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate the mid index
        if (v[mid] == target) {
            return mid; // If target is found, return its index
        } else if (v[mid] < target) {
            start = mid + 1; // If target is greater, ignore left half
        } else {
            end = mid - 1; // If target is smaller, ignore right half
        }
    }
    return ans; // Return -1 if target is not found
}

int findPi(vector<int> nums) {
    int s = 0;
    int e = nums.size() - 1;
    int pi = -1;
    int mid;
    while (s <= e) {
        mid = s + (e - s) / 2; // Calculate the mid index
        if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
            return mid; // If mid element is greater than next element, mid is the pivot
        } else if (nums[mid] < nums[0]) {
            e = mid - 1; // If mid element is less than the first element, pivot is in left half
        } else {
            s = mid + 1; // If mid element is greater than or equal to the first element, pivot is in right half
        }
    }
    pi = nums.size() - 1; // If no pivot found, return last index
    return pi;
}

#include <vector>
using namespace std;

bool searchIn2DMatrix(vector<vector<int>>& matrix, int target) {
    // Start from the top-right corner of the matrix
    int col = matrix[0].size() - 1;
    int row = 0;

    // Continue the search while within the bounds of the matrix
    while (row < matrix.size() && col >= 0) {
        // If the current element is equal to the target, return true
        if (matrix[row][col] == target) {
            return true;
        }
        // If the current element is greater than the target, move left
        else if (matrix[row][col] > target) {
            col--;
        }
        // If the current element is less than the target, move down
        else {
            row++;
        }
    }
    // If we reach here, the target is not in the matrix
    return false;
}


int searchInRotatedArray(vector<int>& nums, int target) {
    int pi = findPi(nums); // Find the pivot index
    if (target >= nums[0] && target <= nums[pi]) { // check if the target is bigger than first index value and smaller or equal  to pivot
        return binarySearch(nums, 0, pi, target); // Search in the left part of the pivot
    } else {
        return binarySearch(nums, pi + 1, nums.size() - 1, target); // Search in the right part of the pivot
    }
}

int findPeak(const std::vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid;
    int ans = -1;
    while (s <= e) {
        mid = s + (e - s) / 2; // Calculate the mid index
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1; // If mid element is less than next element, peak is in right half
        } else {
            ans = mid; // If mid element is greater than or equal to next element, update answer
            e = mid - 1; // Search in left half
        }
    }
    return ans; // Return the peak index
}

int nearestSqaureRoot(int n) {
    int start = 1;
    int end = n;
    int mid;
    int ans = -1;
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate the mid index
        long long int product = static_cast<long long int>(mid) * mid; // bcz bigger value can overflow and casting one mid to long so that result is in long otherwise will be in int
        if (product == n) {
            ans = mid; // If mid squared is equal to n, return mid
            break;
        }
        if (product < n) {
            ans = mid; // If mid squared is less than n, update answer
            start = mid + 1; // Search in right half
        } else {
            end = mid - 1; // If mid squared is greater than n, search in left half
        }
    }
    return ans; // Return the nearest square root
}

double findExactSqrt(int number) {

       auto base = double(nearestSqaureRoot(number));;
        double ans;
       for (double i = base; i*i<=number; i = i+0.001) {
           cout<<"the ith is now ->"<<i<<endl;
           ans = i;
       }
    cout<<ans;
    return ans;

}

/**
 * FIND QUOTIENT WIHTOUD "/" ... BT DOESNT WORK WITH VALUES OUT OF INT RANGE
 * This function finds the quotient of a given dividend and divisor using a binary search approach.
 * It handles both positive and negative values for dividend and divisor, ensuring the correct sign
 * of the result based on the signs of the input values.
 *
 * @param divisor The divisor value and it will never be equal to 0.
 * @param dividend The dividend value.
 */
void findQuotient(int divisor, int dividend) {
    // Use absolute values for the binary search
    int absDivisor = abs(divisor);
    int absDividend = abs(dividend);

    // Initialize start and end for the binary search range
    int start = 0;
    int end = absDividend;

    // Initialize ans to -1 to handle cases where no valid quotient is found
    int ans = -1;
    int quotient;

    // Perform binary search to find the quotient
    while (start <= end) {
        // Calculate the middle point of the current range
        quotient = start + (end - start) / 2;

        // Check if the current middle point is a valid quotient
        if (quotient * absDivisor <= absDividend) {
            // If valid, update ans and move start to search in the upper half
            ans = quotient;
            start = quotient + 1;
        } else {
            // If not valid, move end to search in the lower half
            end = quotient - 1;
        }
    }

    // Adjust the sign of the result if the divisor and dividend have opposite signs
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        ans = -ans;
    }

    // Output the result
    cout << "The quotient for the dividend (" << dividend << ") and divisor (" << divisor << ") is -> " << ans;
}

// int divide(int dividend, int divisor) {
//    // Handle overflow
//     if (dividend == INT_MIN && divisor == -1) {
//         return INT_MAX;
//     }
//
//     // Determine the sign of the result
//     int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
//
//     // Work with absolute values to simplify calculations
//     long long absDividend = labs(dividend);
//     long long absDivisor = labs(divisor);
//
//     // Initialize the quotient
//     int quotient = 0;
//
//     // The highest bit we can shift divisor without exceeding dividend
//     for (int i = 31; i >= 0; --i) {
//         long long i1 = absDividend >> i;
//         if (i1 >= absDivisor) {
//             long long i2 = absDivisor << i;
//             absDividend -= i2;
//             quotient += 1 << i;
//         }
//     }
//
//     // Apply the sign to the quotient
//     quotient *= sign;
//
//     // Ensure the result is within the 32-bit signed integer range
//     return quotient;
// }

//practice the divide bitwise method
/**
 * A function that divides two integers without using multiplication, division, or mod operator.
 *
 * This function uses bitwise operations to determine the maximum number of times the divisor can
 * fit into the dividend by doubling the divisor each time.
 *
 * @param divisor A non-zero divisor
 * @param divident The dividend to be divided
 * @return Quotient after dividing dividend by divisor
 */
int divide(int divisor, int divident) {
    // Handle overflow edge case
    if (divident == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if (divident == INT_MIN && divisor == 1) {
        return INT_MIN;
    }

    // Convert divisor and dividend to their absolute values for simplicity
    long long absDivisor = abs((long long)divisor);
    long long absDivident = abs((long long)divident);

    // Determine the sign of the result
    int sign = (divisor > 0) == (divident > 0) ? 1 : -1;
    int q = 0;

    // Loop until the absolute dividend is greater than or equal to the absolute divisor
    while (absDivident >= absDivisor) {
        long long tempDivisor = absDivisor; // Temporary divisor to store the current multiple of the divisor
        int multiple = 1; // Track how many times the divisor can fit into the current dividend portion

        // Double the temporary divisor until it is greater than the remaining dividend
        while (absDivident >= (tempDivisor << 1)) {
            tempDivisor <<= 1; // Double the temporary divisor
            multiple <<= 1; // Double the multiple count
        }

        // Subtract the largest found multiple of the divisor from the dividend
        absDivident -= tempDivisor;
        // Add the multiple count to the quotient
        q += multiple;
    }

    // Apply the sign to the result
    return q * sign;
}


void findElementIndexInNearlySortedArray(const std::vector<int> & v, int target) {
    int start = 0;
    int end = v.size()-1;
    int mid;
    int ans = -1;
    while (start<=end) {
        mid = start + (end-start)/2;

        if (v[mid]==target) {
            ans = target;
        }

        if (v[mid-1]==target) {
            ans = mid-1;
        }

        if (v[mid+1]==target) {
            ans = mid+1;
        }

        if (mid <= v.size()-2 && v[mid]<target) {
            start = mid+2;
        }
        if(mid >= 2 && v[mid]<target){
            end = mid-2;
        }
    }
    cout<<"the ans is at index ->"<<ans;
}

int main() {
    vector<int> v = { 4,5,6,7,2,3};
    // vector<int> v = { 3,10, 40, 20, 50, 80, 70};
    // int pivot = searchInRotatedArray(v,2);
    // cout<<pivot;
    // cout<<findExactSqrt(53);
    // cout<<divide(1,2147483647);

    int target = 70;
    findElementIndexInNearlySortedArray(v,target);

}
