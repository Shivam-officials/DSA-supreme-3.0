#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/jump-game/

// SC = O(2^N)  TC = O(N) // note: did not understood completely  how exactly... bt  its just what chatgpt said 

// Recursive function to check if we can reach the last index
bool canJumpRe(vector<int> &nums, int index) {
    // Base case: if we're at the last index, return true
    if(index == nums.size() - 1) return true;
    
    // If the index goes out of bounds, return false
    if(index >= nums.size()) return false;
    
    bool recurAns = false; // To keep track if any path can reach the end
    
    // Try jumping to all positions within the allowed range (1 to nums[index] steps)
    for(int i = 1; i <= nums[index]; i++) {
        bool ans = canJumpRe(nums, index + i); // Recursive call to check if we can jump from the new index
        recurAns = recurAns || ans; // If any path leads to true, set recurAns to true
    }
    
    return recurAns;
}

int main() {
    // vector<int> nums{3, 2, 1, 0, 4}; // Example input.
      vector<int> nums{2,3,1,1,4};
    cout << canJumpRe(nums, 0); // Starting from the first index
    return 0;
}
