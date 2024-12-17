#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

// fixme: TC = cant calculate for now bcz of decrease in branch size as we proceed
// Helper function to find unique combinations
void combinationSumHelper(vector<int>& candidates, int target, int start,
                          vector<int>& currentVector, vector<vector<int>>& ans) {
    // Base case: If target is 0, add the current combination to the result
    if (target == 0) {
        ans.push_back(currentVector);
        return;
    }

    // Stop recursion if we run out of candidates
    if (start >= candidates.size()) return;

    // Iterate through the candidates starting from 'start'
    for (int i = start; i < candidates.size(); i++) {
        // Skip duplicates to ensure unique combinations
        if (i > start && candidates[i] == candidates[i - 1]) continue;

        // Include candidate if it does not exceed the remaining target
        if (candidates[i] <= target) {
            currentVector.push_back(candidates[i]); // Choose candidate
            // Recurse with reduced target and move to the next candidate
            combinationSumHelper(candidates, target - candidates[i], i + 1, currentVector, ans);
            currentVector.pop_back(); // Backtrack to explore other combinations
        }
    }
}

// Main function to solve the problem
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans; // Result to store all unique combinations
    vector<int> currentVector; // Current combination being explored
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    combinationSumHelper(candidates, target, 0, currentVector, ans); // Start recursion

    // Return the result
    return ans;
}

int main(int argc, char const* argv[]) {
    // Test case with a large input of 1s
    vector<int> candidates{10,1,2,7,6,1,5};
    auto ans = combinationSum2(candidates, 8);

    // Print the result
    for (auto ar : ans) {
        for (auto elm : ar) {
            cout << elm << " ";
        }
        cout << endl;
    }
    return 0;
}
