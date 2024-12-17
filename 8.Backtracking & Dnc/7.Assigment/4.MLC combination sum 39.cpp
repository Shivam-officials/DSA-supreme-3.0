#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/combination-sum/description/

// fixme: TC = cant calculate for now bcz of decrease in branch size as we proceed
void combinationSumHelper(vector<int> &candidates, int target, int start,
                          vector<int> &currentVector,
                          vector<vector<int>> &ans) {
  // Base case: If target becomes 0, add the current combination to the result
  if (target == 0) {
    ans.push_back(currentVector);
    return; // Return after adding the valid combination
  }

  // If start index exceeds the size of candidates, return (no more elements to
  // process)
  if (start >= candidates.size())
    return;

  // Iterate through candidates starting from 'start' index
  for (int i = start; i < candidates.size(); i++) {
    if (candidates[i] <= target) { // Check if the current candidate can contribute to the target
      currentVector.push_back(candidates[i]); // Include the candidate
      // Recurse with updated target and the same 'i' to allow reusing the same
      // element
      combinationSumHelper(candidates, target - candidates[i], i, currentVector,
                           ans);
      currentVector.pop_back(); // Backtrack to explore other combinations
    }
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> ans;   // Result to store all combinations
  vector<int> currentVector; // Current combination being explored
  combinationSumHelper(candidates, target, 0, currentVector, ans); // Start the recursion
  return ans;                // Return the list of valid combinations
}

int main(int argc, char const *argv[]) {
  vector<int> nums{2, 3, 6, 7};
  auto ans = combinationSum(nums, 7);
  for (auto ar : ans) {
    for (auto elm : ar) {
      cout << elm << " ";
    }
    cout << endl;
  }
  return 0;
}
