
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// simple though- if next value is bigger then append it otherwise if it can be smallest end then use it for smallest end

/**
 INTUTION
 Objective: Find the length of the longest increasing subsequence (LIS).

 Approach:

 Use a vector ans to track the smallest possible end elements of increasing subsequences of various lengths.
 For each element in the input array nums:
 [If the element is larger than the last element in ans]: It extends the current longest subsequence, so push_back it to ans.
 [If the element is smaller or equal]: Find the appropriate position in ans to replace an existing element, ensuring that ans maintains the smallest possible end elements for subsequences of the same length. This replacement helps in keeping ans flexible for future elements by allowing us to compare more elements with smaller current end which would allow us to check potential bigger subsequnce length possible or not .
 Why This Works:

 By maintaining the smallest end elements, the algorithm ensures that ans can accommodate new elements in a way that potentially extends the length of the LIS.
 Replacing elements in ans does not affect the length of the LIS but allows ans to stay optimal for future elements, making the solution efficient.
*/
int lengthOfLIS(vector<int>& nums) 
{
    // Initialize a vector to store the smallest possible end elements of increasing subsequences.
    vector<int> ans;
    
    // Base case: push the first element of `nums` into `ans`.
    ans.push_back(nums[0]);
    
    // Iterate over the remaining elements in the `nums` vector.
    for(int i = 1; i < nums.size(); i++)
    {
        // If the current element `nums[i]` is greater than the last element in `ans`,
        // it extends the longest increasing subsequence found so far.
        if(nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            // Find the position where `nums[i]` should be placed in `ans` to maintain
            // the increasing order. `lower_bound` finds the first position where
            // `nums[i]` can be inserted without violating the increasing order. 
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            
            // Replace the element at `index` with `nums[i]` to maintain the smallest
            // possible end element for subsequences of length `index + 1`.
            ans[index] = nums[i];
        }
    } 

    // Print the elements of `ans` (not part of the LIS length computation but for debugging).
    for (auto elm : ans) {
        cout << elm << endl;
    }   
    
    // Return the size of `ans`, which represents the length of the longest increasing subsequence.
    return ans.size();
}


int main()
{
    // vector<int>v{2,3,4,34,2,1,02,03,-1};
    vector<int>v{10, 9, 2, 5, 3, 7, 101, 18};
    // sort(v.begin(),v.end());
    cout << lengthOfLIS(v);
    return 0;
}