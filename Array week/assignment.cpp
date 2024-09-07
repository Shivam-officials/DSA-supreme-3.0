#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 *
 * this is the week 3 assignment of the array topics which contains all the questions
 */
void show1dVector(vector<int> nums) {
    cout << "\nthe array is \n";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
void sortColors(vector<int> &nums) {
    /** counting sort like approach
     * Sorting by iterating over the array and replacing with increasing index value.
     * This method uses a counting sort-like approach where we move elements of the
     * same color together in a single pass.

    int color = 0;
    int index = 0;
    while (color < 3) {
        for (int i = 0; i < nums.size(); i++) {
            if (color == nums[i]) {
                swap(nums[index++], nums[i]);
            }
        }
        color++;
    }
    */
    // Uncomment the above block if you want to use the counting sort approach.

    /**
     * 3-pointer approach (Dutch National Flag problem)
     *
     * This approach uses three pointers:
     * - `low`: points to the boundary of the next position for `0`.
     * - `medium`: the current element under consideration.
     * - `high`: points to the boundary of the next position for `2`.
     *
     * The idea is to partition the array into three parts:
     * - Elements less than `1` (i.e., `0`) are moved to the beginning.
     * - Elements equal to `1` remain in the middle.
     * - Elements greater than `1` (i.e., `2`) are moved to the end.
     */
    int low, medium, high;
    low = medium = 0;
    high = nums.size() - 1;

    while (medium <= high) {
        if (nums[medium] == 0) {
            // If the element is 0, swap it with the element at `low` and move both `low` and `medium` forward.
            swap(nums[low++], nums[medium++]);
        } else if (nums[medium] == 1) {
            // If the element is 1, just move `medium` forward.
            medium++;
        } else {
            // If the element is 2, swap it with the element at `high` and move `high` backward.
            // Do not move `medium` forward here to re-evaluate the swapped element.
            swap(nums[medium], nums[high--]);
        }
    }

    // Display the sorted array
    show1dVector(nums);
}

// Function to check if array has 2 elements
// whose sum is equal to the given value
bool hasArrayTwoCandidates(vector<int> &arr, int x) {
    /**
     * Two-pointer approach
     * - The array is sorted first.
     * - Two pointers, `low` and `high`, are initialized at the beginning and end of the array.
     * - If the sum of elements at these pointers equals the target, return true.
     * - If the sum is less than the target, move the `low` pointer forward.
     * - If the sum is greater than the target, move the `high` pointer backward.
     * - The array is sorted to ensure that all pairs are considered.
     */
    sort(arr.begin(), arr.end()); // TC -> O(nlogn)
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        //TC -> 0(n)
        int sum = arr[low] + arr[high];

        if (sum == x) {
            return true; // return true if sum is equal to target bcz pair found
        } else if (sum < x) {
            low++; // if sum is less than target move low forward
        } else {
            high--; // if sum is more than target move high backward
        }
    }

    return false;
}

int missingNumber(vector<int> &nums) {
    /**
     * XOR approach
     * - The XOR of all elements in the array and all numbers from 0 to n gives the missing number.
     * - XORing the same number twice cancels it out, leaving only the missing number.
     */
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
    }

    for (int i = 0; i <= nums.size(); i++) {
        ans ^= i;
    }
    return ans;

    /** sum approach
     * - The sum of the first n natural numbers is calculated.
     * - The sum of elements in the array is subtracted from this sum.
     * - The result is the missing number.
     */
}

int pivotIndexByBruteForce(vector<int> &nums) {
    /**
     * Brute-force approach
     * - For each element, calculate the sum of elements to the left and right.
     * - If the sums are equal, return the current index.
     * - This approach has a time complexity of O(n^2).
     */
    for (int i = 0; i < nums.size(); ++i) {
        int sumLeft = 0;
        int sumRight = 0;

        for (int j = 0; j < i; ++j) {
            sumLeft += nums[j];
        }

        for (int j = i + 1; j < nums.size(); ++j) {
            sumRight += nums[j];
        }

        if (sumLeft == sumRight) {
            return i;
        }
    }
    return -1;
}

int pivotIndexByPrefixSumApproachBySir(std::vector<int> &nums) {
    /**
     * Prefix sum approach
     * - Two arrays are used to store the cumulative sums from the left and right.
     * - The pivot index is found where the sum of elements to the left equals the sum of elements to the right.
     */
    vector<int> lSum(nums.size(), 0);
    vector<int> rSum(nums.size(), 0);

    // every ith index holds the sum of previous left of all elements till i -1
    for (int i = 1; i < nums.size(); i++) {
        lSum[i] = lSum[i - 1] + nums[i - 1];
    }

    // every ith index holds the sum of next  of all elements from i+1 to last index
    for (int i = nums.size() - 2; i >= 0; i--) {
        rSum[i] = rSum[i + 1] + nums[i + 1];
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (rSum.at(i) == lSum.at(i)) {
            return i;
        }
    }

    return -1;
}

// better for upper pivotIndex wala question
void leftRightSumEqualIndex2(vector<int> v) {
    /**
     * Intuition:
     * 
     * The problem is to find an index in the array such that the sum of elements to the left 
     * of this index is equal to the sum of elements to the right of it. 
     * 
     * Instead of calculating the left and right sums for each index (which would be inefficient),
     * we use two pointers approach to simulate the process.
     * 
     * We start with two pointers: `start` (beginning of the array) and `end` (end of the array).
     * We also maintain two sums: `lsum` (sum from the left side) and `rSum` (sum from the right side).
     * 
     * The idea is to move these pointers towards each other:
     *  - If `lsum` (left sum) is less than `rSum` (right sum), we add the element at `start` to `lsum` 
     *    and move the `start` pointer to the right.
     *  - If `rSum` is less than `lsum`, we add the element at `end` to `rSum` and move the `end` pointer 
     *    to the left.
     *  - If `lsum` equals `rSum`, we check if the pointers meet. If they do, it means we found the index 
     *    where the left sum equals the right sum. Otherwise, we continue moving the `start` pointer.
     * 
     * The process continues until the pointers meet or cross each other, and by that time, 
     * if no valid index is found, we conclude that no such index exists.
     */
    
    long long start =  0, end = v.size()-1, lsum = 0, rSum = 0;

    while (start <= end) {
        if (lsum == rSum && start == end) {
            // If both sums are equal and pointers meet, we found the index
            cout << "ans is at :" << start << " index";
            return;
        }

        if (start == end) {
            // If pointers meet but sums are not equal, no such index exists
            cout << "there is no such ans";
            return;
        }

        if (lsum > rSum) {
            // If left sum is greater, add the element at the end to the right sum and move the end pointer left
            rSum += v[end--];
        } else if (lsum < rSum) {
            // If right sum is greater, add the element at the start to the left sum and move the start pointer right
            lsum += v[start++];
        } else {
            // If both sums are equal but pointers haven't met, continue to move the start pointer
            rSum += v[end--];
        }
    }
}

int removeDuplicates(vector<int> &nums) {
    /**
     * In-place removal of duplicates in a sorted array
     * - Iterate through the array, and when a new unique element is found, move it to the next available position.
     * - The `nextIndex` keeps track of where the next unique element should be placed.
     * - The function returns the new length of the array after duplicates are removed.
     */
    int un = nums[0]; // let the 1st element be the unique element
    int nextIndex = 1;
    for (int i = 1; i < nums.size(); i++) {
        // if the ith element does match with unique element (all the same elements will be togethor bcz of sorting)
        // then make that different element unique and swap that with the nextIndex and then increase nextIndex
        if (un != nums[i]) {
            un = nums[i];
            nums[nextIndex++] = nums[i];

        }
    }
    return nextIndex;
}

double findMaxAverage(vector<int> &nums, int k) {
    // sliding window approach by sir
    int left = 0;
    int high = k;
    double sum = 0;
    // sum of first window
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }

    double maxSum = sum;
    while (high < nums.size()) {
        // find the sum of next subArray by adding the next array item and removing the first array item from previous subArray
        // meaning shifting the window to the right by 1
        sum = sum + nums[high++] - nums[left++];
        maxSum = max(maxSum, sum);
    }
    return maxSum / k;

}

void moveAllNegativeNumberToLeftSide(vector<int> &v) {
    /**
 * moveAllNegativeNumberToLeftSide
 *
 * This function rearranges the elements of the input vector such that all negative numbers
 * are moved to the left side of the vector. The relative order of the negative numbers is
 * maintained, but the relative order of the non-negative numbers is not guaranteed.
 *
 * Approach:
 * - Use a single pointer (`index`) to track the position where the next negative number
 *   should be placed.
 * - Iterate through the vector with another pointer (`i`).
 * - Whenever a negative number is encountered, swap it with the element at the `index`
 *   position and increment the `index`.
 * - This ensures that all negative numbers are moved to the left side of the vector.
 */
    /** //count sort approach
    int index = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < 0) {
            // Swap the current element with the element at the `index` position
            swap(v[index++], v[i]);
        }
    }
    // Display the rearranged vector
    show1dVector(v);
    */

    // /** // dutch national flag approach in 3 categories
    int low, medium, high;
    low = medium = 0;
    high = v.size() - 1;

    while (medium <= high) {
        if (v[medium] < 0) {
            // If the element is negative (less than 0), swap it with the element at `low` and move both `low` and `medium` forward.
            swap(v[low++], v[medium++]);
        } else if (v[medium] == 0) {
            // If the element is 0, just move `medium` forward.
            medium++;
        } else {
            // If the element is postive (more than 0), swap it with the element at `high` and move `high` backward.
            // Do not move `medium` forward here to re-evaluate the swapped element.
            swap(v[medium], v[high--]);
        }
    }
    show1dVector(v);

    //*// check if the left side has -ve number if it is increment the low otherwise keep it at that place and
    // check that the high rightmost element is positive if it is make it decrement by 1 otherwise keep it at that place
    // and if upper those condition are not met swap the elements

    // int low  = 0 ;
    // int high = v.size() - 1;
    //
    // while (low < high) {
    //     if (v[low] < 0) {
    //         low++;
    //     } else if (v[high]>0) {
    //         high--;
    //     } else {
    //         swap(v[low],v[high]);
    //
    //     }
    // }
    // show1dVector(v);
}

// by dutch nation approach
void moveZeroes(vector<int> &nums) {
    int low = 0;
    int high = nums.size() - 1;
    int medium = 0;
    while (medium <= high) {
        if (nums[medium] != 0) swap(nums[low++], nums[medium++]);

        if (nums[medium] == 0) medium++;
    }
    show1dVector(nums);
}

int findDuplicate(vector<int> &nums) {
    /**  // negative marking method
      int ans = -1;
      // Iterate through the array
      for (int i = 0; i < nums.size(); i++) {
          // Get the absolute value of the current element to handle previously modified elements
          int index = abs(nums[i]);

          // Check if the value at nums[index] is negative or we have visited it before
          if (nums[index] < 0) {
              // If it is negative, we found our duplicate
              ans = index;
              break; // Exit the loop immediately after finding the duplicate
          }

          // Mark the value at nums[index] as visited by making it negative
          nums[index] *= -1;
      }

      // Return the duplicate value found
      return ans;
      */

    // todo positioning method  ... bt u can also use cycle sort

    // Continue swapping elements until nums[0] equals  to equivalent index (nums[nums[0]]) ..
    // it will cause the  duplicate value to come at 0th index
    while (nums[0] != nums[nums[0]]) {
        // Swap nums[0] with nums[nums[0]]
        swap(nums[0], nums[nums[0]]);
    }

    // Return the duplicate number found
    return nums[0];
}


void missingAnElementFromArrayWithDuplicate(std::vector<int> &nums) {
    show1dVector(nums);
    /**  // negative marking method
     for (int i = 0; i < nums.size(); ++i) {
         // we are minusing 1 from index bcz the integer contain n(10) integer from 1 to n(10) so last index will be n -1 (9)
         // we cant visit n(10) index it will give us out of bound thats why we are minusing 1 from each value to make it
         //index within bound and thus we will visit every equivalent index value except the missing number  and mark every
         //number  negative except missing index then we will then return the index of that positive nmber after adding 1
         // to it bcz we subracted 1 from each value (remember ) to compensate if we dont then we will always
         // be getting the 1 less value than out real ans and  thus we will get our the ans
         int index = abs(nums[i])-1;

         if (nums[index] > 0) {
             nums[index] *= -1;
         }

     }

     for (int i = 0; i < nums.size(); ++i) {
         if (nums[i]>0) {
             cout<<i+1<<" ";
         }
     }

     */

    // swapping and sorting method (cyclic sort)
    int i = 0;
    while (i < nums.size()) {
        int correctIndex = nums[i] - 1;
        if (nums[i] != nums[correctIndex]) {
            swap(nums[i], nums[correctIndex]);
        } else {
            i++;
        }
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            cout << i + 1 << " ";
        }
    }

    show1dVector(nums);
}

// there can be multiple repeated elements bt u have to return the first index of first repeated number
//[1, 5, 3, 4, 3, 5, 6] there are 5,3 are both repeated bt i have to return the index (1- based) of 5 as it is first
// repeated number
int firstRepeated(vector<int> &arr) {
    // hashing technique TC O(n) and SC O(n)
    // Create an unordered_map to store the frequency of each element
    unordered_map<int, int> hash;

    // Iterate over the array to count the occurrences of each element
    for (int i = 0; i < arr.size(); i++) {
        ++hash[arr[i]]; // Increment the count of the element in the map
    }



    // Iterate over the array again to find the first repeated element
    for (int i = 0; i < arr.size(); i++) {
        if (hash[arr[i]] > 1) {
            // Check if the element has more than one occurrence
            return i + 1; // Return the 1-based index of the first repeated element
        }
    }

    // If no repeated element is found, return -1
    return -1;
}


vector<int> findCommonInThreeArrays(const vector<int> &arr1, const vector<int> &arr2, const vector<int> &arr3) {
    /**   // hashing apprach   NAIVE APPROACH
    // Create an unordered_map to store the frequency of elements across the arrays
    unordered_map<int, int> hash;

    // Step 1: Mark the presence of elements in arr1
    for (auto ele : arr1) {
        hash[ele] = 1; // Set the initial value to 1 indicating presence in arr1
    }

    // Step 2: Mark the presence of elements in arr2 if they are also in arr1
    for (auto ele : arr2) {
        if (hash[ele] == 1) { // Check if element is already marked from arr1
            hash[ele] = 2; // Update the value to 2 indicating presence in both arr1 and arr2
        }
    }

    // Step 3: Mark the presence of elements in arr3 if they are in both arr1 and arr2
    for (auto ele : arr3) {
        if (hash[ele] == 2) { // Check if element is marked from both arr1 and arr2
            hash[ele] = 3; // Update the value to 3 indicating presence in arr1, arr2, and arr3
        }
    }

    // Create a vector to store the common elements
    vector<int> ans;

    // Step 4: Collect elements that are common in all three arrays
    for (auto entry : hash) {
        cout << entry.first << " -> " << entry.second << endl; // Print the element and its frequency value
        if (entry.second == 3) { // Check if the element is marked as present in all three arrays
            ans.push_back(entry.first); // Add the element to the result vector
        }
    }

    // Step 5: If no common element is found, add -1 to the result vector
    if (ans.empty()) {
        ans.push_back(-1); // Indicate no common elements found
    }

    return ans; // Return the result vector
    */

    // 3 pointer method
    // in which u compare the values from 3 pointer if they are equeal then they are common otherwise u
    // increment the smallest numbers pointers by 1
    // btw can also use set to insert the value to avoid duplicates

    // Initialize starting indexes for A[], B[] and C[]
    int i = 0, j = 0, k = 0;
    int n1, n2, n3;
    n1 = arr1.size();
    n2 = arr2.size();
    n3 = arr3.size();
    vector<int> A = arr1;
    vector<int> B = arr2;
    vector<int> C = arr3;
    vector<int> common;

    // Iterate through three arrays while all arrays have elements
    while (i < n1 && j < n2 && k < n3) {
        // If A[i] = B[j] = C[k], push A[i] to common elements
        if (A[i] == B[j] && B[j] == C[k]) {
            common.push_back(A[i]);
            i++;
            j++;
            k++;
            // Skip duplicate elements in A[]
            while (i < n1 && A[i] == A[i - 1])
                i++;

            // Skip duplicate elements in B[]
            while (j < n2 && B[j] == B[j - 1])
                j++;

            // Skip duplicate elements in C[]
            while (k < n3 && C[k] == C[k - 1])
                k++;
        }
        /** in else cases incrementing the smallest number's pointer by 1*/
        //smallest number wali best approach hai

        // if A[i] is smallest incrementing i by 1
        else if (A[i] < B[j] && A[i] < C[k]) // OR A[i] < B[j] ..  If A[i] < B[j], then ith element cannot be common
            i++;

            //  if B[i] is smallest incrementing j by 1
        else if (B[j] < C[k] && B[j] < A[i]) // OR B[j] < C[k]..If B[j] < C[k], then jth element cannot be common
            j++;

            // else C[i] is smallest.. incrementing k by 1
        else
            k++; // If C[k] is smallest, then kth element cannot be
    }

    return common;
}

void printWaveMatrixColWise(std::vector<std::vector<int> > &matrix) {
    /** // my approach
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row ,col;

    row = col = 0;
    while (row <= rows-1 && col < cols) {
        cout<<matrix[row][col]<<" ";

        // increase the col if it is even or decrease it if odd
        if (col & 1  ) {
                row--;
        }
        else
            row++;
        // printing the first and last element of every col and then increment the col by 1
        if (row == rows-1 || row == 0) {
            cout<< matrix[row][col]<< " "<<endl;
            col = col+1;
        }
    }
    */

    //sir approach start with the column and decide if its even or odd column and through that print rows
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int col = 0; col < cols; ++col) {
        if (col & 1) {
            // col is odd then start from last row to 1st printing

            for (int row = rows - 1; row >= 0; --row) {
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        } else {
            for (int row = 0; row < rows; ++row) {
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        }
    }
}

void printWaveMatrixRowWise(std::vector<std::vector<int> > &matrix) {
    /** // my approach
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row ,col;
    row = col = 0;
    while (row < rows && col < cols) {
        cout<<matrix[row][col]<<" ";

        // increase the col if it is even or decrease it if odd
        if (row & 1  ) {
                col--;
        }
        else
            col++;

        // printing the first and last element of every row and then increment the row by 1
        if (col == cols-1 || col == 0) {
            cout<< matrix[row][col]<< " "<<endl;
            row = row+1;
        }
    } */

    // sir approach
    //sir approach start with the column and decide if its even or odd column and through that print rows
    // acc to it
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int row = 0; row < cols; ++row) {
        if (row & 1) {
            // col is odd then start from last row to 1st printing

            for (int col = cols - 1; col >= 0; --col) {
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        } else {
            for (int col = 0; col < cols; ++col) {
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        }
    }
}

std::vector<int> spiralOrder(std::vector<std::vector<int> > matrix) {
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();

    int total_elements = rows * cols;

    int startingRow = 0;
    int endingCol = cols - 1;
    int endingRow = rows - 1;
    int startingCol = 0;
    int count = 0;
    while (count < total_elements) {
        //printing startRow from left to right
        for (int i = startingCol; i <= endingCol && count < total_elements; ++i) {
            cout << matrix[startingRow][i] << " ";
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;


        // printing ending col up to down
        for (int i = startingRow; i <= endingRow && count < total_elements; ++i) {
            cout << matrix[i][endingCol] << " ";
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;


        // printing endingRow from right to left
        for (int i = endingCol; i >= startingCol && count < total_elements; --i) {
            cout << matrix[endingRow][i] << " ";
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;


        //printing startingCol from down to up
        for (int i = endingRow; i >= startingRow && count < total_elements; --i) {
            cout << matrix[i][startingCol] << " ";
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

// add two number represented as array
string calc_Sum(int *a, int n, int *b, int m) {
    // Complete the function
    int i, j;
    //getting the lastindex of each array to start the adding from there to 1st
    i = n - 1;
    j = m - 1;
    string output;
    int carry = 0;
    while (i >= 0 && j >= 0) {
        int digit = a[i] + b[j] + carry;
        int ans = digit % 10;
        //insert is heavy operation so we are using pushback to minimise time complexity
        output.push_back(ans + '0');
        carry = digit / 10;
        i--, j--;
    }

    //if the a array is still left while b is finished
    while (i >= 0) {
        int digit = a[i--] + carry + 0;
        int ans = digit % 10;
        carry = digit / 10;
        output.push_back(ans + '0');
    }
    //if the b array is still left while a is finished
    while (j >= 0) {
        int digit = b[j--] + carry + 0;
        int ans = digit % 10;
        carry = digit / 10;
        output.push_back(ans + '0');
    }

    // if carry is left add that to the array
    if (carry != 0) {
        output.push_back(carry + '0');
    }

    // we are removing the last zero bcz after reversing them those zeroes will be useless
    while (output[output.size() - 1] == '0') {
        output.pop_back();
    }

    // we were adding the ans to the string in the last index so our
    // ans is in reverse order so we have to use reverse function to get the real ans;
    reverse(output.begin(), output.end());
    return output;
}

vector<int> LargeNumberFactorial(int N) {
    // code
    vector<int> output;
    output.push_back(1);
    // int index = 0;
    for (int i = 2; i <= N; i++) {
        int carry = 0;
        int j = 0; // counter for output Array from 0 to its last index
        // while(j <= output.size() - 1){
        // if u use j counter from 0 to last index then u have to reverse the ans
        // in the following case u r using last index to 0 so u dont have to reverse it
        for (int j = output.size() - 1; j >= 0; --j) {
            int digit = output[j] * i + carry;
            int ans = digit % 10;
            output[j] = ans;
            carry = digit / 10;
            // j++;
        }

        // if carry is left non zero then we will also store it digit wise in the array
        while (carry) {
            int ans = carry % 10;
            // output.push_back(carry); // we will push carry to the end if we are tranversing left to right for multiplication
            output.insert(output.begin(), ans);
            // we will insert the carry at the leftmost positioon if we are doign right to left multiplication
            carry /= 10;
        }
    }

    /** if we r doing multiplication from left to right  side instead of right to left side
    // then we have to reverse the ans to get the ans */

    // reverse(output.begin(),output.end());

    return output;
}

vector<vector<int>> threeSumMine(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  for (int i = 0; i < nums.size(); i++) {
    // skiping the duplicate first
    // while(nums[i]==nums[i+1] && i < nums.size()-1){ // it will move the fix
    // element one step ahead resulting one less low to high range to make the
    // triplet combination so better to make sure that u avoid using the
    // previously used values like the below to stop the fixed element moving
    // ahead  and this will make the triplets to be unique sets of values
    // without usign the set
    while (i > 0 && nums[i] == nums[i - 1] && i < nums.size()) {
      i++;
    }

    int low = i + 1;

    int high = nums.size() - 1;

    while (low < high) {

      int sum = nums[i] + nums[low] + nums[high];
      if (sum == 0) {
        vector<int> temp{nums[i], nums[low], nums[high]};
        ans.push_back(temp);

        while (low < high && nums[low] == nums[low + 1])
          low++;

        while (low < high && nums[high] == nums[high - 1])
          high--;

        low++;
        high--;
      } else if (sum > 0) {
        high--;
      } else {
        low++;
      }
    }
  }
  return ans;
}

int main() {
    // vector<int> v = {1,7,3,6,5,6};
    // vector<int> v = {7,4,5,8,8,3,9,8,7,6};
    vector<int> v = {5, 3, 6, -4, 6, 0, 0, -9, 43, -38, 0, 45, 34};
    // vector<int> v = {1,2,-3,4,-5,6};
    // vector<int> v = {2,0,2,1,1,0};
    vector<int> nums = {1, 2, 1, 2, 3};
    vector<int> arr1 = {1, 5, 10, 20, 40, 40, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};
    // cout<<hasArrayTwoCandidates(v,target);

    // cout<< pivotIndex(v);
    // int pivot_index  = pivotIndexByPrefixSumApproach(v);

    // std::cout << pivot_index;

    // cout << findMaxAverage(v, 1);

    // sortColors(v);

    // moveAllNegativeNumberToLeftSide(v);
    // cout<<findDuplicate(nums);
    // moveZeroes(nums);
    // cout << findDuplicate(nums);

    // missingAnElementFromArrayWithDuplicate(nums);


    // cout<<"code runs";

    // vector<int>ans =  findCommonInThreeArrays(arr1,arr2,arr3);
    // show1dVector(ans);
    // cout<<"code runs";

    vector<vector<int> > matrix(4, vector<int>(0, 4));
    matrix =
            // {
            // {01,02,03,04,05},
            // {06,07,8,9,10},
            // {11,12,13,14,15},
            // {16,17,18,19,20},
            // {21,22,23,24,25} };
            {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                // {13,14,15,16}
            };

    // printWaveMatrixColWise(matrix);
    // printWaveMatrixRowWise(matrix);
    // vector<int> order = spiralOrder(matrix);
    // show1dVector(order);
    cout << "enter the number u want to see the factorial";
    int N;
    cin >> N;

    show1dVector(LargeNumberFactorial(N));
}
