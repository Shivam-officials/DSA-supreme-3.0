#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to check if cutting trees at a certain height will yield
// at least the required amount of wood (requiredMeters).
bool isSolution(vector<int>& trees, int height, int requiredMeters) {
    int woodCollected = 0;

    // For each tree, check how much wood would be collected if cut at 'height'
    for (auto el : trees) {
        if (el >= height) {
            // Only collect wood if the tree is taller than or equal to the saw blade height
            woodCollected += el - height;

             // Early exit if we've collected enough wood
            if (woodCollected >= requiredMeters) return true;
        }

    }
    // Return true if the wood collected meets or exceeds the requirement
    return woodCollected >= requiredMeters;
}

// Function to find the maximum saw blade height such that cutting at that height
// will still yield at least 'm' meters of wood.
int maxSawBladeHeight(vector<int> &trees, int m) {
    // Start of binary search, the minimum height is 0
    int start = 0;

    // The maximum possible saw blade height is the tallest tree
    int end = *max_element(trees.begin(), trees.end());

    // Variable to store the best possible height
    int ans = 0;

    // Binary search for the optimal saw blade height
    while (start <= end) {
        // Midpoint of the current range (safer calculation to prevent overflow)
        int mid = start + (end - start) / 2;

        // If cutting at this height collects enough wood
        if (isSolution(trees, mid, m)) {
            // This is a valid solution, but try for a higher height
            ans = mid;
            start = mid + 1;
        } else {
            // Not enough wood collected, lower the saw blade height
            end = mid - 1;
        }
    }

    // Return the maximum valid saw blade height
    return ans;
}

// int main() {
//     // Vector of tree heights
//     vector<int> v{4, 42, 40, 26, 46};

//     // Find and print the maximum saw blade height that allows collecting at least 20 meters of wood
//     cout << maxSawBladeHeight(v, 20);
// }

int main() {
    int n, m;
    
    // Read number of trees and required meters of wood
    cin >> n >> m;
    
    // Vector to store the heights of the trees
    vector<int> trees(n);
    
    // Read the height of each tree
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }
    
    // Find the maximum saw blade height and output the result
    cout << maxSawBladeHeight(trees, m) << endl;

    return 0;
}