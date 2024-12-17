#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// https://leetcode.com/problems/beautiful-arrangement/description/

// TC = O(N!) 
void countArrangementHelperRe(vector<int> &nums, int start, int &ans)
{
    // Base case: If 'start' reaches the end of the array, we found a valid arrangement
    if (start == nums.size())
    {
        ans++;
        return;
    }

    // Iterate over the array elements starting from 'start'
    for (int i = start; i < nums.size(); i++)
    {
        // Check if the current number at index 'i' can be placed at 'start' position
        if (!(nums[i] % (start + 1) == 0 || (start + 1) % nums[i] == 0)) 
            continue; // Skip if neither condition is satisfied

        // Swap to move the current number to the 'start' position
        swap(nums[i], nums[start]);
        
        // Recursively try to arrange the next elements
        countArrangementHelperRe(nums, start + 1, ans);
        
        // Backtrack: Restore the original order after the recursive call
        swap(nums[i], nums[start]);
    }
}

// TC = O(N!.N) SC=O(N)
int countArrangement(int n) {
    vector<int> nums;
    
    // Fill the vector with numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    
    int ans = 0;
    
    // Start the recursive arrangement from the first position
    countArrangementHelperRe(nums, 0, ans);
    
    return ans; // Return the total number of valid arrangements
}

int main(int argc, char const *argv[])
{
    int n = 3; // Input value

    cout << countArrangement(n); // Output the number of beautiful arrangements

    return 0;
}
