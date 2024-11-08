#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/jump-game-ii/description/


// SC = O(2^N)  TC = O(N) // note: did not understood completely  how exactly... bt  its just what chatgpt said 
// Recursive function to find the minimum jumps needed to reach the end of the array
void canJumpRe(vector<int> &nums, int index, int steps, int &ans) {
    // Base case: if we reach the last index, update the minimum steps
    if (index == nums.size() - 1) {
        ans = min(ans, steps);
        return;
    }
    
    // If index goes out of bounds, return
    if (index >= nums.size()) return;
    
    // Try all possible jumps from 1 up to nums[index] steps forward
    for (int i = 1; i <= nums[index]; i++) {
        canJumpRe(nums, index + i, steps + 1, ans); // Recursive call with updated position and steps
    }
}

int main() {
    // vector<int> nums{2, 3, 1, 1, 4}; // Example input
    vector<int> nums{3, 2, 1, 0, 4}; // Example input.
    int ans = INT_MAX;
    canJumpRe(nums, 0, 0, ans); // Start from the first index
    cout << ans; // Output the minimum jumps needed
    return 0;
}


