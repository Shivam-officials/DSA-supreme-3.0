#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;



// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

// TC = O(N^M)  SC = O(M) where m = row and n = row

// Recursive function to minimize the difference between the sum and target
int minimizeTheDifferenceRe(vector<vector<int>> &mat, int row, int &target, int sum) {
    // Base case: if we've reached the last row, return the absolute difference
    if (row == mat.size()) {
        return abs(sum - target);
    }

    // Initialize minimum difference
    int minDiff = INT_MAX;
    // Explore all options in the current row
    for (int i = 0; i < mat[0].size(); i++) {
        int recurAns = minimizeTheDifferenceRe(mat, row + 1, target, sum + mat[row][i]);
        minDiff = min(minDiff, recurAns); // Track minimum difference
    }
    return minDiff;
}



void solve_video_Code(vector<vector<int>> &mat, int &target, int sum, int row, int &mini)
    {
        if (row == mat.size())
        {
            mini = min(mini, abs(target - sum));
            return;
        }

        for (int col = 0; col < mat[row].size(); col++)
        {
            solve_video_Code(mat, target, sum + mat[row][col], row + 1, mini);
        }
    }

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 13;
    cout << minimizeTheDifferenceRe(mat, 0, target, 0)<<endl;
    int mini = INT_MAX;
    solve_video_Code(mat, target, 0, 0, mini);
    cout << mini;
    return 0;
}

