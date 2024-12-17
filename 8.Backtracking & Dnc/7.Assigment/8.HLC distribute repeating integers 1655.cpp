#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/distribute-repeating-integers/description/

// fixme: passed 97 test cases out of 109 then TLE
bool canDistributeHelper_ME(vector<int> &nums, vector<int> &quantity,
                            unordered_map<int, int> occurances, int start) {
  // base case
  if (start == quantity.size()) {
    return true;
  }

  int currentQuantity = quantity[start];

  for (auto &pair : occurances) {
    if (currentQuantity <= pair.second) {
      pair.second = pair.second - currentQuantity;
      //  visited[start] = true;
      if (canDistributeHelper_ME(nums, quantity, occurances, start + 1)) {
        return true;
      }
      // visited[start] = false;
      pair.second = pair.second + currentQuantity;
    }
  }
  return false;
}

// idea:OPTIMISATION  Instead of iterating on a hashmap (unordered_map), which
// is slower, store all the pair.second values (frequencies) in a vector and
// iterate on it. This significantly improves runtime for large datasets.

// TC=  O(n * m) SC = O(n)
bool canDistributeHelper_Sir(vector<int> &quantity, vector<int> &occurances,
                             int start) {
  // Base case: All customers' quantities are successfully distributed
  if (start == quantity.size()) {
    return true;
  }

  int currentQuantity = quantity[start];

  // Try to allocate the current quantity to one of the remaining frequencies
  for (auto &occur : occurances) {
    if (currentQuantity <= occur) {
      occur -= currentQuantity; // Deduct quantity
      if (canDistributeHelper_Sir(quantity, occurances, start + 1)) {
        return true; // Successfully distributed
      }
      occur += currentQuantity; // Backtrack to restore state
    }
  }
  return false; // Unable to distribute the current quantity
}

/*Time Complexity:
    1. Count frequencies: O(k)  (k = size of nums)
    2. Store frequencies: O(m)  (m = unique elements)
    3. Sort quantity: O(n log n) (n = size of quantity)
    4. Recursive backtracking: O(n * m)

    Overall Time Complexity: O(n * m) (dominates for large n and m)

    Space Complexity: O(m + n)
    - m for frequency vector, n for recursion stack.
*/
bool canDistribute(vector<int> &nums, vector<int> &quantity) {
  unordered_map<int, int> occurances; // Map to count frequencies of elements
  vector<int> count;                  // Vector to store frequencies

  // Count occurrences of each element
  for (auto elm : nums) {
    occurances[elm]++;
  }

  // Save frequencies into the count vector
  for (auto pair : occurances) {
    count.push_back(pair.second);
  }

  // Sort quantities in descending order for optimization
  sort(quantity.rbegin(), quantity.rend());

  // Helper function to check if distribution is possible
  return canDistributeHelper_Sir(quantity, count, 0);
  //   return canDistributeHelper_ME(nums,quantity,occurances,0);
}

int main(int argc, char const *argv[]) {
  vector<int> nums{1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,
                   8,  9,  9,  10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15,
                   16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23,
                   23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30,
                   31, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38,
                   38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45,
                   46, 46, 47, 47, 48, 48, 49, 49, 50, 50};
  vector<int> quantity{2, 2, 2, 2, 2, 2, 2, 2, 2, 3};

  cout << canDistribute(nums, quantity);
  return 0;
}
