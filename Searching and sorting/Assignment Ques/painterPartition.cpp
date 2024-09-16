#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

bool painterRequirement(int arr[], long long currentMin, int n, int k) {
    int painterRequired = 1;  // Start with 1 painter
    
    long long currentBoardSum = 0;  // Sum of boards assigned to the current painter
    for (int i = 0; i < n; i++) {
        int board = arr[i];
        
        // If a single board exceeds the currentMin, it's impossible to paint it
        if (board > currentMin) {
            return false;
        }
        
        // If adding this board exceeds the limit, assign a new painter
        if (currentBoardSum + board > currentMin) {
            painterRequired++;
            currentBoardSum = board;  // Start new painter's load with this board
        } else {
            currentBoardSum += board;  // Add board to current painter's load
        }
    }
    
    // Return true if the number of painters required is within the allowed number
    return painterRequired <= k;
}


long long minTime(int arr[], int n, int k) {
    // Initialize the search bounds
    long long start = *max_element(arr, arr + n);  // Minimum possible time is the largest board
    long long end = 0;  // Maximum possible time is the sum of all boards
    
    // Calculate the total sum of board sizes
    for (int i = 0; i < n; i++) {
        end += arr[i];
    }
    
    long long mid;
    long long ans = -1;
    
    // If number of painters is greater than or equal to the number of boards,
    // each painter can handle exactly one board
    if (k >= n) {
        return start; // time taken to paint the biggest board will be ans
    }
    
    // Binary search for the minimum time
    while (start <= end) {
        mid = start + (end - start) / 2;  // Find the middle point
        
        // Check if it's feasible to paint within `mid` time
        if (painterRequirement(arr, mid, n, k)) {
            ans = mid;  // Update the answer
            end = mid - 1;  // Try for a smaller time
        } else {
            start = mid + 1;  // Increase the time
        }
    }
    
    return ans;
}


int main(int argc, char const *argv[])
{
    int v[] = {5 ,10 ,30, 20 ,15};
    cout << minTime(v, 5,3);
    return 0;
}
