#include <iostream>
using namespace std;

void print(int** board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



bool check_position(int** board, int col, int row, int n) {
    // Check if any queen exists in the current row
    for (int j = 0; j < n; j++) {
        if (board[row][j]) return false;
    }

    // Check if any queen exists in the current column
    for (int i = 0; i < n; i++) {
        if (board[i][col]) return false;
    }

    //note: if iterating over row from 0 to n then we can caclulate the diogonals if do row+col - currentrow(i) then we will get the top-right to left bottom on diogonal of that specific ROW, COL elements and if do currentRow (i) - row + col then we will get the top left to bottom right diogonal of that specific ROW COL element
    
    // Check the top-right to bottom-left diagonal (row + col is constant)
    for (int i = 0; i < n; i++) {
        if ((row + col - i) >= n || (row + col - i < 0)) continue; // Skip out-of-bounds cells
        if (board[i][row + col - i]) return false;
    }

    // Check the top-left to bottom-right diagonal (row - col is constant)
    for (int i = 0; i < n; i++) {
        if ((i - row + col) >= n || (i - row + col < 0)) continue; // Skip out-of-bounds cells
        if (board[i][i - row + col]) return false;
    }

    // If no conflicts, the position is valid
    return true;
}


bool backtracing(int** board, int n, int row){
    // if(row > n){
    if(row >= n){
        print(board,n);
        return true;
    }
    for(int j=0; j<n; j++){
        if(check_position(board,j,row,n)){
            board[row][j] = 1;
            backtracing(board, n, row+1);
            board[row][j] = 0;
        }
    }
    return false;
}

void placeNQueens(int n){
    int** board = new int*[n];
    for(int i=0; i<n; i++){
        board[i] = new int[n];
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    backtracing(board, n, 0);
}

int main(int argc, char const *argv[])
{
    placeNQueens(4);
    return 0;
}
