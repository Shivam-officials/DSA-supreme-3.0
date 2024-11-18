#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;


// TC = O(3^(m*n))  SC = O(m+n) 

// Function to find the size of the largest square of 1s starting at cell (i, j)
int maxSquareSize(vector<vector<char>> &square, int i, int j, int &maxi) {
    // Base case: If the current cell is out of bounds, return 0 (no square possible)
    if (i >= square.size() || j >= square[0].size()) {
        return 0;
    }

    // Recursively calculate the size of squares in three directions:
    // 1. To the right of the current cell
    int side = maxSquareSize(square, i, j + 1, maxi);

    // 2. Diagonally down to the bottom-right
    int belowSide = maxSquareSize(square, i + 1, j + 1, maxi);

    // 3. Directly below the current cell
    int below = maxSquareSize(square, i + 1, j, maxi);

    // If the current cell is '1', calculate the size of the square
    if (square[i][j] == '1') {
        // A square can only be formed if the current cell is '1'.
        // Its size is 1 plus the minimum of the size of squares formed in the three directions.
        int foundSquareSize = 1 + min(side, min(belowSide, below));

        // Update the maximum square size found so far
        maxi = max(maxi, foundSquareSize);

        // Return the size of the square that can be formed with this cell as the top-left corner
        return foundSquareSize;
    } else {
        // If the current cell is '0', it cannot contribute to a square
        return 0;
    }
}

int main() {
    // Input binary matrix
    vector<vector<char>> square{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };

    // Variable to store the size of the largest square found
    int ans = 0;

    // Call the recursive function starting from the top-left corner of the matrix
    maxSquareSize(square, 0, 0, ans);

    // Output the area of the largest square (size^2)
    cout << ans * ans;

    return 0;
}

