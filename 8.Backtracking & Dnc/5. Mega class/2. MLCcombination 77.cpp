#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/combinations/description/

// TC = O(2^N) SC = O(N);
//INTUTION just like subsequence include/exclude ques and the catch here is that add only to ans if size becames k 
void combinations_solve_ME(int n, int index, int k, vector<int>& currentV, vector<vector<int>>& ans) {
    // If current combination size equals k, add it to the result
    if (currentV.size() == k) {
        ans.push_back(currentV);
        return;
    }

    // If index exceeds n, no further combinations are possible
    if (index > n) {
        return;
    }

    // Include the current index in the combination
    currentV.push_back(index);
    combinations_solve_ME(n, index + 1, k, currentV, ans);
    
    // Exclude the current index and move to the next
    currentV.pop_back();
    combinations_solve_ME(n, index + 1, k, currentV, ans);
}

//!TC = ?
void combinations_solve_sir(int &n, int &k,int start,vector<int>&currentVector ,vector<vector<int>>&ans){
    //base case 
    if(currentVector.size() == k){
        
        ans.push_back(currentVector);
    }
    

    for (int i = start ; i <= n; i++) {
        currentVector.push_back(i);
        combinations_solve_sir(n, k, i+1, currentVector, ans);
        currentVector.pop_back();
    }

}

vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> ans; // Store all valid combinations
    vector<int> currentV;    // Current combination being built
    
    // Start recursive generation with index 1
    // combinations_solve_ME(n, 1, k, currentV, ans);
    combinations_solve_sir(n, k, 1, currentV, ans);
    
    return ans;
}


int main()
{
    int n = 4 , k =2;

    auto ans = combinations(n,k);
    for (auto batch : ans) {
        for (auto elm  : batch) {
            cout << elm <<" ";
        }
        cout << endl;
    }
    
    return 0;
}
