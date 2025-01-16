#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// https://www.spoj.com/problems/PRATA/ 

//idea: this code is right spoj test cases are wrong with ans data

// TC = O(n * RequiredParathas * log(maxRank * RequiredParathas ^ 2))

// Function to check if it is possible to cook the required number of prathas
// within the given assumed time using the provided chefs.
bool isPossibleSolution(vector<int> &chefs, int requiredPrathas, int assumedTime) {

    int cookedPrathas = 0;

    // Loop through each chef's rank (cooking speed).
    for (auto rank : chefs) {
         int timeSpent = 0;
        int k = 1;

       // Calculate how many prathas the chef can cook within the assumed time
        while (timeSpent + rank * k <= assumedTime) {
            timeSpent += rank * k;  // Add time taken for the k-th pratha
            cookedPrathas++;
            k++;

            // Early exit if enough prathas are cooked
            if (cookedPrathas >= requiredPrathas) {
                return true;  
            }
        }
        
    }

    // Output the debug information for the number of prathas cooked for the assumed time.
    cout << "Cooked prathas for assumed time " << assumedTime << " is " << cookedPrathas << endl;

    // Return true if the total number of cooked prathas is greater than or equal to the required prathas.
    return cookedPrathas >= requiredPrathas;
}

// Function to find the minimum time required to cook the required number of prathas.
int findMinTimeToCompleteOrder(vector<int> &chefs, int RequiredParathas) {

    // Start of the binary search range (minimum time).
    int start = 0;

    // Find the chef with the maximum rank to calculate the worst-case scenario.
    int maxRank = *max_element(chefs.begin(), chefs.end());
    
    // End of the binary search range (maximum possible time for worst-case scenario).
    int end = maxRank * RequiredParathas * (RequiredParathas + 1)/2; // O(n^2)

    int mid;
    int ans = -1;

    // Perform binary search to find the minimum time.
    while (start <= end) {
        mid = (start + end) >> 1;  // Calculate the middle point.

        // Check if it's possible to cook the required prathas within 'mid' time.
        if (isPossibleSolution(chefs, RequiredParathas, mid)) {
            ans = mid;       // If possible, store the answer and try for a smaller time.
            end = mid - 1;   // Adjust the binary search to the left half.
        } else {
            start = mid + 1; // If not possible, adjust the search to the right half.
        }
    }

    // Return the minimum time found.
    return ans;
}

int main() {
    // Example vector of chef ranks (all chefs have the same rank here).
    vector<int> v{ 1, 1};

    // Find and print the minimum time to cook 8 prathas with the given chefs.
    cout << findMinTimeToCompleteOrder(v, 8);

    return 0;
}

// int main() {
//     int T;
//     cin >> T;
    
//     // Process each test case
//     while (T--) {
//         int P, L;
//         cin >> P >> L;
//         vector<int> chefs(L);

//         for (int i = 0; i < L; i++) {
//             cin >> chefs[i];
//         }

//         // Output the minimum time to cook P prathas
//         cout << findMinTimeToCompleteOrder(chefs, P) << endl;
//     }

//     return 0;
// }
