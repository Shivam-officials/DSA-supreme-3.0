#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sudoku-solver/description/

// Time complexity: O(9(N*N)), For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)).
// Space Complexity: O(N*N), To store the output array a matrix is needed.

// Checks if placing 'option' at board[row][col] is valid
bool isSafe(vector<vector<char>>& board, int row, int col, char option) {
    // Check row for duplicate
    for (int k = 0; k < 9; k++) { 
        // Iterate through all columns in the given row to check for duplicates
        if (board[row][k] == option) {
            return false; // Duplicate found in the row
        }
    }

    // Check column for duplicate
    for (int k = 0; k < 9; k++) { 
        // Iterate through all rows in the given column to check for duplicates
        if (board[k][col] == option) {
            return false; // Duplicate found in the column
        }
    }

    // Check 3x3 sub-grid for duplicate
    /** Way 1 for sub-grid check: Using mathematical computation  // LOVE BABBAR WAY
        for (int k = 0; k < 9; k++) {
            int x = 3 * (row / 3) + k / 3; // Row index in the sub-grid
            int y = 3 * (col / 3) + k % 3; // Column index in the sub-grid
            if (board[x][y] == option) {
                return false; // Duplicate found in the sub-grid
            }
        }
    */

    // Way 2: More intuitive method using nested loops  //LAKSHAY WAY
    int startRow = row - (row % 3); // Calculate the starting row of the 3x3 sub-grid
    int startCol = col - (col % 3); // Calculate the starting column of the 3x3 sub-grid
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            int translated_row = i + startRow; // Calculate the row index in the sub-grid
            int translated_col = j + startCol; // Calculate the column index in the sub-grid
            if (board[translated_row][translated_col] == option) {
                return false; // Duplicate found in the sub-grid
            }
        }
    }

    return true; // No duplicates found, placement is valid
}

// Solves the Sudoku puzzle using backtracking
bool sodukuSolve(vector<vector<char>>& board, int size) {
    // Find empty cell
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == '.') { // Empty cell found
                // Try placing numbers '1' to '9'
                for (char options = '1'; options <= '9'; options++) {
                    if (isSafe(board, i, j, options)) { // Check if valid
                        board[i][j] = options;         // Place number
                        if (sodukuSolve(board, size)) { // Recursive solve
                            return true;
                        } else {
                            board[i][j] = '.';          // Backtrack
                        }
                    }
                }
                return false; // No valid number, trigger backtracking
            }
        }
    }
    return true; // Solved if no empty cells remain
}

int main() {
    // Initial Sudoku board with empty cells as '.'
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    // Solve the Sudoku puzzle
    sodukuSolve(board, 9);

    // Print the solved board
    for (auto row : board) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
