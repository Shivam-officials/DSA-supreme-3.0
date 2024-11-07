#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/

/** question 
    Given an integer array nums, return true if you can partition the array into
    two subsets such that the sum of the elements in both subsets is equal or false
    otherwise.



    Example 1:

    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
    Example 2:

    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The array cannot be partitioned into equal sum subsets.
*/

// TC = O(2^N)  Sc = O(N*2^N)... due to the auxiliary vectors.

// Recursive function to determine if we can partition 'nums' into two subsets
// with equal sums
bool canReturnRe_ME_MoreUnderstandbleBtHIghSpaceComplexityDueToVectorCopying(
    vector<int> &nums, int index, vector<int> include, vector<int> exclude) {
  // Base case: if we've considered all elements, check if the sums of both
  // subsets are equal
  if (index == nums.size()) {
    int sumA = 0, sumB = 0;

    // Calculate the sum of elements in the 'include' subset
    for (auto element : include) {
      cout << element << " ";
      sumA += element;
    }
    cout << "-------";

    // Calculate the sum of elements in the 'exclude' subset
    for (auto element : exclude) {
      cout << element << " ";
      sumB += element;
    }
    cout << "=================" << endl;

    // Return true if sums of both subsets are equal
    return sumA == sumB;
  }

  // Recursive case A: include current element in 'include' subset
  include.push_back(nums[index]);
  bool caseA =
      canReturnRe_ME_MoreUnderstandbleBtHIghSpaceComplexityDueToVectorCopying(
          nums, index + 1, include, exclude);

  // Backtrack by removing the last element added to 'include'
  include.pop_back();

  // Recursive case B: include current element in 'exclude' subset
  exclude.push_back(nums[index]);
  bool caseB =
      canReturnRe_ME_MoreUnderstandbleBtHIghSpaceComplexityDueToVectorCopying(
          nums, index + 1, include, exclude);

  // Return true if either of the recursive cases found a valid partition
  return caseA || caseB;
}

// TC = O(2^N)  Sc = O(N)
bool canReturnRe_ME_Optimised(vector<int> &nums, int index, int include,int exclude) {
  // Base case: if we've considered all elements, check if the sums of both
  // subsets are equal
  if (index == nums.size()) {
    // Return true if sums of both subsets are equal
    return include == exclude;
  }

  // Recursive case A: include current element in 'include' subset
  bool caseA =
      canReturnRe_ME_Optimised(nums, index + 1, include + nums[index], exclude);

  // Recursive case B: include current element in 'exclude' subset
  bool caseB =
      canReturnRe_ME_Optimised(nums, index + 1, include, exclude + nums[index]);

  // Return true if either of the recursive cases found a valid partition
  return caseA || caseB;
}


// note: INTUTION --- The intuition behind this code is based on the concept of subset sum. Here, we're trying to see if we can divide an array into two equal parts, meaning each part has the same sum. This problem is essentially about finding whether there exists a subset of the array that adds up to half the total sum. If such a subset exists, then the rest of the elements will naturally sum up to the other half, achieving an equal partition
// Recursive function to check if a subset with the given target sum exists
bool canReturnRe_Sir(vector<int> &nums, int index, int target) {
    // Base case: If we've checked all elements
    if(index == nums.size()) {
        // Check if the target sum is zero, meaning we found a valid subset
        return target == 0;
    }

    // Recursive case: Try including and excluding the current element

    // Option 1: Include the current element in the subset
    bool include = canReturnRe_Sir(nums, index + 1, target - nums[index]);
    
    // Option 2: Exclude the current element from the subset
    bool exclude = canReturnRe_Sir(nums, index + 1, target);

    // Return true if either including or excluding leads to a valid subset
    return include || exclude;
}

int main() {
  vector<int> nums{1, 5, 11, 5}; // Test case that should return true
  // vector<int> nums{1, 2, 3, 5}; // Test case that should return false

  vector<int> include{};
  vector<int> exclude{};

  cout<< canReturnRe_ME_MoreUnderstandbleBtHIghSpaceComplexityDueToVectorCopying( nums, 0, include, exclude)<< endl;
  cout << canReturnRe_ME_Optimised(nums, 0, 0, 0) << endl;
  cout << "-----------------------------------------------------------------------------------------------";
  int sum = accumulate(nums.begin(), nums.end(), 0);

    // If the sum is odd, it's impossible to partition it into two equal subsets
    if (sum & 1) {
        cout << "This is not possible because an odd sum can't be divided into two equal parts.";
    } else {
        // Call the recursive function with target as half of the total sum
        cout << canReturnRe_Sir(nums, 0, sum / 2);
    }

  return 0;
}
