#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

//!TC = cant solve for now according to current knowledge base
int minScoreTriangulation(vector<int> &values, int i, int j) {
    // Base case: 
    // If there are only two vertices left (i + 1 == j), no triangle can be formed, so return 0.
    if (i + 1 == j) return 0;

    int ans = INT_MAX; // Initialize the minimum score as the maximum possible value.

    // Iterate over all possible points `k` between `i` and `j` to try splitting the polygon.
    // `k` represents the vertex that forms a triangle with vertices `i` and `j`.
    for (int k = i + 1; k < j; k++) {
        // **Current triangle contribution**:
        // The triangle formed by vertices `i`, `j`, and `k` has a score of `values[i] * values[j] * values[k]`.
        // Add the score of this triangle to the scores of the remaining subproblems:
        // - Subproblem (i, k): Solve for the polygon formed by vertices from `i` to `k`.
        // - Subproblem (k, j): Solve for the polygon formed by vertices from `k` to `j`.
        int recurAns = values[i] * values[j] * values[k] 
                     + minScoreTriangulation(values, i, k)  // Solve the left subproblem
                     + minScoreTriangulation(values, k, j); // Solve the right subproblem

        // Update the minimum score for this subproblem `(i, j)`
        ans = min(ans, recurAns);
    }

    // Return the minimum triangulation score for vertices `i` to `j`.
    return ans;
}
 

int main()
{
    // vector<int>values{ 26,35,78,22,14,62,30,21,86,7,70,67,8,28,61,33,3,78,18,71 };  //TLE
    vector<int>values{ 1,3,1,4,1,5 };
    int n = values.size();
    cout <<  minScoreTriangulation(values,0,n-1);
    
    return 0;
}
