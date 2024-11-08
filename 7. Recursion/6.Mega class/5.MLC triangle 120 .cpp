#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/triangle/description/

// SC = O(2^N)  TC = O(N) 
// Recursive function to find the minimum path sum from top to bottom of the triangle
int minimumTotalRe(vector<vector<int>> &triangle, int row, int index) {
    // Base case: If we've reached beyond the last row, return 0
    if (row == triangle.size()) {
        return 0;
    }

    // Recursive cases: Calculate path sums by moving down and down-right
    int down = triangle[row][index] + minimumTotalRe(triangle, row + 1, index);
    int downPlus = triangle[row][index] + minimumTotalRe(triangle, row + 1, index + 1);

    // Return the minimum path sum of the two choices
    return min(down, downPlus);
}

int main() {
    vector<vector<int>> mat = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << minimumTotalRe(mat, 0, 0); // Start from the top of the triangle
    return 0;
}

