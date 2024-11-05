#include <iostream>
#include <climits>
using namespace std;

// https://leetcode.com/problems/perfect-squares/description/

// Function to find the minimum number of perfect squares that sum up to n

// TC =  O((√n)^n).BCZ At each level, the function can branch up to √n times and maximum depth n 
// SC = O(n) // maximum depth of stack (n bcz of 1)
int numSquareRe(int n) {
    // Base case: If n is 0, no squares are needed
    if (n == 0) return 0;

    int ans = INT_MAX; // Initialize the answer to a large value (maximum possible integer)

    // Iterate over all possible perfect squares less than or equal to n
    for (int i = 1; i * i <= n; i++) {
        // Recursive call to find the minimum squares needed for the remaining value (n - i*i)
        int perfectSquareUsed = 1 + numSquareRe(n - (i * i));

        // Update the answer with the minimum value found
        ans = min(ans, perfectSquareUsed);
    }

    // Return the minimum number of perfect squares needed to form n
    return ans;
}

int main(int argc, char const *argv[]) {
    int n = 13; // Example input: find the minimum number of perfect squares that sum up to 13

    // Call the recursive function and print the result
    cout << numSquareRe(n);

    return 0;
}
