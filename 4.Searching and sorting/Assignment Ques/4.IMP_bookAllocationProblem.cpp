#include <bits/stdc++.h>
#include <climits>
using namespace std;


// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1


// Time Complexity: O(n * log(sum - max)), Space Complexity: O(1)

/**
 * @note This problem involves finding the minimum possible maximum sum of a subarray
 * when the number of subarrays is fixed. You can also find the highest sum by adjusting
 * the binary search approach to maximize the sum.
 */


// Utility function to check how many students (or partitions) are required
// when the maximum sum of pages (or board lengths) for a student is curr_min.
bool studentRequired(int arr[], int n, int curr_min, int m) {
    int students = 1;  // At least one student is required
    int curr_sum = 0;

    // Traverse through the array to allocate books (or boards) to students
    for (int i = 0; i < n; i++) {

        if(arr[i]>curr_min)
        {
            return false;
        }
        
        // If adding the current element exceeds curr_min,
        // allocate books (or boards) to a new student
        if (curr_sum + arr[i] > curr_min) {
            students++;  // Increment student count
            curr_sum = arr[i];  // Start new student's allocation with current element
        } else {
            curr_sum += arr[i];  // Otherwise, add current element to current student's allocation
        }
    }
    return students <= m;  // Return the number of students required
}

// Function to find the minimum possible maximum sum of pages when partitioned into m students

/**
 * @note INTUTION : simple we will take the search space of ans and then use binary search to navigate to the solution by verifying 
 *  each mid points that it can be ans (by treating mid as the maximum value as sum of all the elemants that an  subarray can hold, by  making        * subarrays while making sure that the sum of subarray does not exceed mid bcz that is the maximum sum of subarray in that permutation and           * combination)ans thus checking how many subarray will be there under these constrains and if  * * number of subarray is greater or equal to current * mid it can a potential ans and we search in left to minimise otherwise in right
 */


int findPages(int arr[], int n, int m) {
    // If there are fewer books (or boards) than students, it's impossible to partition, so return -1
    if (n < m) {
        return -1;
    }

    // Find the total sum using accumulate and the maximum single element
    int sum = accumulate(arr, arr + n, 0);  // Using accumulate to find the total sum
    int mx = *max_element(arr, arr + n);    // Finding the maximum element

    // Initialize the binary search bounds
    int start = mx, end = sum;
    int result = INT_MAX;

    // Perform binary search to find the minimum possible maximum sum
    while (start <= end) {
        int mid = (start + end) / 2;  // Mid represents the current "maximum sum" we're testing

        

        // If the number of students required is less than or equal to the given number of students,
        // then this mid could be a potential answer, but we try to minimize it by going left.
        if (studentRequired(arr, n, mid,m)) {
            result = mid;  // Store the current mid as a potential answer
            end = mid - 1;  // Move left to try and find a smaller valid maximum sum
        } else {
            // If the number of students required is more than the given number of students, it means
            // the current mid is too small, and we need to increase it by moving right.
            start = mid + 1;
        }
    }

    // Return the result, which is the minimum possible maximum sum
    return result;
}

// Driver code
int main() {
    // Array representing the number of pages in books (or lengths of boards)
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; // Number of students (or painters)

    // Output the minimum number of pages (or maximum board length) that the most loaded student will have
    cout << "Minimum number of pages = " << findPages(arr, n, m) << endl;
    return 0;
}
