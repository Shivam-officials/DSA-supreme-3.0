#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// LC 532 https://leetcode.com/problems/k-diff-pairs-in-an-array/



 bool bsElementFound(vector<int> nums, int start, int target)
        {
            int end = nums.size() - 1;
            if (target > nums[end])
            {
                return false;
            }
            int mid;
            while (start <= end)
            {
                mid = start + (end - start) / 2;

                if (nums[mid] == target)
                {
                    return true;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            return false;
}



// space complexity = 0(n2) and TC = 0(n)
int k_diff_uniquePair_twoPointer(vector<int> nums, int k) {

  set<pair<int, int>> setOfUniquePairs;  // A set to store unique pairs with difference k
  int low = 0;

  sort(nums.begin(), nums.end());  // Sort the array to use two-pointer technique
  int high = low + 1;  // Initialize the high pointer to start after low pointer
  
  while (high <= nums.size() - 1) {  // Iterate as long as high is within bounds

    int diff = nums[high] - nums[low];  // Compute the difference between the current pair

    if (k == diff) {  // If the difference matches k
      setOfUniquePairs.insert({nums[low], nums[high]});  // Add the pair to the set (sorted order ensures uniqueness)
      low++;  // Move the low pointer forward
      high++;  // Move the high pointer forward
    } else if (diff > k) {  // If the difference is greater than k
      low++;  // Move the low pointer forward to reduce the difference
    } else {  // If the difference is less than k
      high++;  // Move the high pointer forward to increase the difference
    }

    if (low == high)  // If the pointers are equal, move the high pointer to avoid having the same element for both pointers
      high++;
  }

  return setOfUniquePairs.size();  // Return the number of unique pairs found
}


// space complexity = 0(n2) and TC = 0(nlogn)
// Function to find all unique pairs in the array with a difference of k
int k_diff_uniquePair_WithBinarySearch(vector<int>& nums, int k) {
        set<pair<int, int>> sets;  // Set to store unique pairs
        sort(nums.begin(), nums.end());  // Sort the array for binary search

        // Iterate through each element to find a pair with difference k
        for (int i = 0; i < nums.size(); i++) {
            int elementToFind = nums[i] + k;  // Calculate the element we need to find
            // Perform binary search to check if elementToFind exists in the subarray after index i
            if (bsElementFound(nums, i + 1, elementToFind)) { /** u can also use here bydefualt binary search funtion */
                sets.insert({ nums[i], elementToFind });  // Insert the pair into the set
            }
        }
        return sets.size();  // Return the number of unique pairs
}



int main() {
  vector<int> nums{1, 3, 1, 5, 4};

  cout << "ans  is " << k_diff_uniquePair_twoPointer(nums, 0);
  set<set<int>> abc;
  set<int> d{3, 4};
  abc.insert(d);

  // auto it =  abc.find({4,3});
  // if(it != abc.end())
  // {
  //   cout << "its found there";
  // }else
  // {
  //   cout << "dont found";
  // }

  return 0;
}
