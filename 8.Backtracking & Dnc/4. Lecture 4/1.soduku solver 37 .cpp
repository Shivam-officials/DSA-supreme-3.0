#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

// Checks if placing 'option' at board[row][col] is valid
bool isSafe(vector<vector<char>>& board, int row, int col, char option) {
    // Check row for duplicate
    for (int k = 0; k < 9; k++) {
        if (board[row][k] == option) {
            return false;
        }
    }
    // Check column for duplicate
    for (int k = 0; k < 9; k++) {
        if (board[k][col] == option) {
            return false;
        }
    }
    // Check 3x3 sub-grid for duplicate
    for (int k = 0; k < 9; k++) {
        int x = 3 * (row / 3) + k / 3;
        int y = 3 * (col / 3) + k % 3;
        if (board[x][y] == option) {
            return false;
        }
    }

    return true; // Valid placement
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
