#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//! time complexity is O(N!) how .. retry to understand after DP

// Global hash maps to track safe placements
unordered_map<int, bool> upDiagonal;
unordered_map<int, bool> rowCheck;
unordered_map<int, bool> downDiagonal;

/**
 * @brief Stores the current board configuration in the results.
 * @complexity Time: O(n^2), Space: O(n)
 */
void storeResult(vector<vector<char>> board, vector<vector<string>> &ans) {
    vector<string> tempAns;
    for (auto row : board) {
        string tempString;
        for (auto chars : row) {
            tempString.push_back(chars);
        }
        tempAns.push_back(tempString);
    }
    ans.push_back(tempAns);
}

/**
 * @brief Checks if placing a queen is safe.
 * @complexity Time: O(1), Space: O(1)
 */
bool isSafe(vector<vector<char>> &board, int row, int col) {
    // return !rowCheck[row] && !upDiagonal[row - col] && !downDiagonal[row + col]; // complex way

    if(rowCheck[row]==true)return false;
    if(upDiagonal[row-col] == true) return false;
    if(downDiagonal[row + col] == true ) return false;

    return true;
}

/**
 * @brief Solves N-Queens using backtracking.
 * @complexity Time: O(n!), Space: O(n) (recursion stack)
 */
void solveNQueens_Backtrack(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans) {
    if (col == n) {
        storeResult(board, ans);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            upDiagonal[row - col] = rowCheck[row] = downDiagonal[row + col] = true;

            solveNQueens_Backtrack(board, col + 1, n, ans);

            board[row][col] = '.';
            upDiagonal[row - col] = rowCheck[row] = downDiagonal[row + col] = false;
        }
    }
}

/**
 * @brief Generates all solutions to the N-Queens problem.
 * @complexity Time: O(n!), Space: O(n^2 + n!) [n^2 for board and n! for all other possible configuratins of queens]
 */
vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    solveNQueens_Backtrack(board, 0, n, ans);
    return ans;
}

int main() {
    int n = 4; // Example: Solve for 4-Queens

    auto ans = solveNQueens(n);

    // Print all valid configurations
    for (auto configuration : ans) {
        for (auto arrangement : configuration) {
            cout << arrangement << "  " << endl;
        }
        cout << endl << endl;
    }

    return 0;
}
