#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/permutations-ii/description/

 // Generates unique permutations using a hash map to track elements in the current recursion
void permutations_BySir(vector<int> &nums, int start, vector<vector<int>> &ans) {

 // Base case: All positions filled
    if (start == nums.size()) {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited; // Tracks elements used in the current call

    for (int i = start; i < nums.size(); i++) {
        if (visited.find(nums[i]) != visited.end()) continue; // Skip duplicates
        visited[nums[i]] = true;
        swap(nums[i], nums[start]); // Swap for permutation
        permutations_BySir(nums, start + 1, ans);
        swap(nums[i], nums[start]); // Backtrack
    }
}

vector<vector<int>> permuteUniqueSir(vector<int>& nums) {
    vector<vector<int>>ans;
    // sort(nums.begin(),nums.end()); // not needed bcz it used hash map to track it is used before or not
    permutations_BySir(nums,0,ans);
    return ans;
}

/** // fixme:32/33 passed 33rd one gave the wrong ans bcz 
    i was checking if it is matching to the start or has been used before by checking it matches with it previous element or not bt that is the mistakes bcz here we swap things so the sorted order will be distorted and it will allow another same variable which has been used before in if it is not equal to start element and is not at the adjacent of position of same variable... thats why i should have used a hashmap to track if the variable has been used in current function before or not
*/

void permutations_ME(vector<int> & nums ,int start,vector<vector<int>>&ans){
        //base case 
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size();i++){
            if(i>start && (( nums[i]==nums[start]) || (nums[i]==nums[i-1]) )) continue;
            // swap(nums[i],nums[start]);
            int temp = nums[i];
            nums[i] = nums[start];
            nums[start] = temp;
            permutations_ME(nums,start+1,ans);
            // swap(nums[i],nums[start]); 
            temp = nums[i];
            nums[i] = nums[start];
            nums[start] = temp;
        }
}

vector<vector<int>> permuteUnique_ME(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    permutations_ME(nums,0,ans);
    return ans;
}



int main(int argc, char const *argv[])
{
    vector<int>nums{1,1,2};
    
    // auto ans = permuteUnique_ME(nums);

    auto ans =permuteUniqueSir(nums);
    for (auto oneset : ans)  {
        for (auto elm : oneset) {
         cout << elm<<" ";
        }
        cout << endl;
    }
    return 0;
}


