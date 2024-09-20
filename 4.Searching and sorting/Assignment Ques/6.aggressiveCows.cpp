
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// https://www.geeksforgeeks.org/problems/aggressive-cows/1



// we are just trying to find out how many cows can be placed under the current circumStances if it is more than or equal to  required we return true
// otherwise false

bool isPossible(vector<int> arr, int distance, int k) {
    // Place the first cow at the first stall
    int pos = arr[0]; 
    int cows = 1;  // First cow placed

    // Try to place the remaining cows
    for (int i = 1; i < arr.size(); i++) {
        // Place cow if the distance between current and last cow is at least 'mid'
        if (arr[i] - pos >= distance) {
            cows++;
            pos = arr[i];  // Update position of last cow placed
        }
    }

    // Check if we managed to place at least 'k' cows
    return cows >= k;
}

// intution : just search in its search space and then navigate to the solution

int solve(int n, int k, vector<int> &stalls) {
    // Sort the stalls to allow binary search
    sort(stalls.begin(), stalls.end());

    // Binary search for the largest minimum distance
    int start = 0, end = stalls[stalls.size() - 1] - stalls[0], ans;
    
    while (start <= end) {
        int mid = (start + end) >> 1;  // Calculate mid distance
        
        // Check if placing 'k' cows with at least 'mid' distance is possible
        if (isPossible(stalls, mid, k)) {
            ans = mid;  // Store the valid answer
            start = mid + 1;  // Try for a larger minimum distance
        } else {
            end = mid - 1;  // Reduce the distance
        }
    }

    return ans;  // Return the largest minimum distance found
}


int main()
{
    vector<int>v{ 10,1,2,7,5 };
    cout << solve(v.size(), 3, v);
    return 0;
}
