#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

//!TC = cant solve for now 
int minScoreTriangulation(vector<int> &values, int i, int j) {
    // Base case: No triangle possible if only two points remain
    if (i + 1 == j) return 0;

    int ans = INT_MAX;
    // Try all possible points `k` to form a triangle with vertices `i` and `j`
    for (int k = i + 1; k < j; k++) {
        // Compute the score for the current triangle and recursively solve for subproblems (recursion relation)
        int recurAns = values[i] * values[j] * values[k] 
                     + minScoreTriangulation(values, i, k) 
                     + minScoreTriangulation(values, k, j);
        // Update the minimum score
        ans = min(ans, recurAns);
    }
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
