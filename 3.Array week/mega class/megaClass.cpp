//
// Created by shivam on 21-07-2024.
//


#include <algorithm>
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printElement(int a ) {
   cout<<a<<" ";
}

// Function to compute the 2's complement of a binary sequence
void twosCompliment(std::vector<int> &v) {

   /** my way
   // Step 1: Flip all the bits (1's complement)
   for (int &i : v) {
      i = !i; // Inverts 0 to 1 and 1 to 0
   }

   // Prepare a vector to store the 2's complement result
   vector<int> output(v.size());
   int carry = 1; // Initialize carry for adding 1 to the inverted bits

   // Step 2: Add 1 to the 1's complement to get 2's complement
   for (int i = v.size() - 1; i >= 0; --i) {
      int sum = v[i] + carry; // Add carry to the current bit
      output[i] = sum % 2;    // The new bit value (0 or 1)
      carry = sum / 2;        // Update carry (0 or 1)
   }

   // If there is a carry left, add it to the result
   if (carry == 1) {
      output.insert(output.begin(), carry); // Insert carry at the beginning
   }

   // Print the result
   for_each(output.begin(), output.end(), printElement);
   cout << std::endl;

   */

   // sir way
   // Step 1: Flip all bits (1's complement)
   for (int &i : v) {
      i = !i;
   }

   // Step 2: Add 1 to the least significant bit to get the 2's complement
   int carry = 1;
   for (int i = v.size() - 1; i >= 0; --i) {
      int sum = v[i] + carry;
      v[i] = sum % 2; // New bit value
      carry = sum / 2; // Carry for the next bit
      // If carry is 0, no need to propagate further
      if (carry == 0) break;
   }

   if (carry) {
      v.insert(v.begin(),carry);
   }

   for_each(v.begin(), v.end(), printElement);
   cout << std::endl;
}

#include <vector>
#include <algorithm> // For std::swap and std::reverse

//roateMatrix the matrix
void roateMatrix(std::vector<std::vector<int>>& matrix) {
   int n = matrix.size(); // Assume square matrix, n x n

   // Step 1: Transpose the matrix
   // Transposing involves swapping matrix[i][j] with matrix[j][i]
   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
         // Swap elements across the diagonal
         std::swap(matrix[i][j], matrix[j][i]);
      }
   }

   // Step 2: Reverse each row
   // After transposing, reverse  each row to complete the 90° clockwise rotation
   for (int i = 0; i < n; i++) {
      std::reverse(matrix[i].begin(), matrix[i].end());
   }
}

//rotate array without any temp array
void rotateArray(vector<int>v,int times){
   int size = v.size();
   times = times%size;

   // step 1 reverse the entire array
   reverse(v.begin(), v.end());

   // step 2 reverse the first times of element
   reverse(v.begin(), v.begin()+times);

   // step 3 reverse the rest of element after the times
   reverse(v.begin()+times, v.end());

   for_each(v.begin(), v.end(), printElement);

}

// Function to find unique triplets that sum up to the target value
vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    
    // Sort the array to use two-pointer technique and handle duplicates
    sort(nums.begin(), nums.end());

    // Iterate through each element as the first element of the triplet
    for (int i = 0; i < nums.size(); ++i) {
        // Skip duplicate elements to avoid repeating the same triplet
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // Initialize two pointers: one just after the fixed element, and one at the end
        int left = i + 1;
        int right = nums.size() - 1;

        // Use the two-pointer technique to find pairs that, along with nums[i], sum to target
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == target) {
                // Found a valid triplet
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicate elements for the 'left' pointer
                while (left < right && nums[left] == nums[left + 1]) {
                    ++left;
                }
                
                // Skip duplicate elements for the 'right' pointer
                while (left < right && nums[right] == nums[right - 1]) {
                    --right;
                }
                
                // Move both pointers to search for new pairs
                ++left;
                --right;
            } else if (sum < target) {
                // Increase the sum by moving the 'left' pointer to the right
                ++left;
            } else {
                // Decrease the sum by moving the 'right' pointer to the left
                --right;
            }
        }
    }
    
    return result;
}



int maxSubArray(vector<int>& nums) {

   /** my way
   int maxsum = INT_MIN;
   for(int i = 0; i < nums.size();i++){
      int sum  = 0;
      for(int j = i; j < nums.size();++j){
         sum += nums[j];
         maxsum = max(maxsum,sum);
      }
   }
   return maxsum;

   */

   // kadane algo sir way jaise hi maxSumEnding -ve ho reset it to zero
   /**  Steps:

      * ADD: Add the current element to the running sum (maxEndingHere).
      * CHECK: Compare maxEndingHere with the maximum sum found so far (maxSoFar).
      * UPDATE: If maxEndingHere is greater than maxSoFar, update maxSoFar.
      * RESET: If maxEndingHere becomes negative, reset it to 0.
*/

       // Initialize variables to keep track of the maximum subarray sum
    int maxSoFar = INT_MIN; // This will store the overall maximum sum
    int maxEndingHere = 0;  // This will store the maximum sum ending at the current position

    // Loop through each element in the array
    for (int i = 0; i < nums.size(); i++) {
        // Add the current element to maxEndingHere
        maxEndingHere += nums[i];

        // Update maxSoFar if maxEndingHere is greater
           maxSoFar = max(maxEndingHere,maxSoFar);

        // If maxEndingHere becomes negative, reset it to 0
        // This is because a negative sum would decrease the total sum of any future subarray
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }

    // Return the maximum subarray sum found
    return maxSoFar;
   
}
int main() {
vector<int> v = {0,1,2,3,4,5,6,7,8,9};
   
}
