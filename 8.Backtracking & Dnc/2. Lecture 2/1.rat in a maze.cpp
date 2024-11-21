#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


// Tc = O(4 ^(n^2))  SC = O(n^2)

// Checks if the given cell (newX, newY) is safe to move
bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int newX, int newY, int n) {
    // Check if newX and newY are within bounds, not a blocked cell, and not already visited
    if (newX >= n || newX < 0 || newY >= n || newY < 0) {
        return false; // Out of bounds
    }
    if (mat[newX][newY] == 0) {
        return false; // Blocked cell
    }
    if (visited[newX][newY]) {
        return false; // Already visited
    }
    return true; // Safe to proceed
}

// Solves the maze recursively using concise logic to explore paths (Left, Right, Up, Down)
void ratInAMazeSolve_concised(vector<vector<int>> &mat, vector<vector<bool>> &visited, int destX, int destY, 
                              int curX, int curY, string outputWay, vector<string> &ans, int n) {
    // Base case: if current position matches destination, add path to result
    if (curX == destX && curY == destY) {
        ans.push_back(outputWay);
        return;
    }

    // Directions: dx and dy represent changes for L, R, U, D
    vector<int> dx{0, 0, -1, 1};
    vector<int> dy{-1, 1, 0, 0};
    vector<string> movements{"L", "R", "U", "D"};

    // Iterate over all directions
    for (int i = 0; i < 4; i++) {
        int newX = curX + dx[i];
        int newY = curY + dy[i];
        if (isSafe(mat, visited, newX, newY, n)) {
            visited[newX][newY] = true; // Mark as visited
            ratInAMazeSolve_concised(mat, visited, destX, destY, newX, newY, outputWay + movements[i], ans, n);
            visited[newX][newY] = false; // Backtrack
        }
    }
}

// Solves the maze recursively by exploring all paths manually (Left, Right, Up, Down)
void ratInAMazeSolve(vector<vector<int>> &mat, vector<vector<bool>> &visited, int destX, int destY, 
                     int curX, int curY, string outputWay, vector<string> &ans, int n) {
    // Base case: if current position matches destination, add path to result
    if (curX == destX && curY == destY) {
        ans.push_back(outputWay);
        return;
    }

    // Move in all directions manually (Left, Right, Up, Down)
    // Left
    int newX = curX, newY = curY - 1;
    if (isSafe(mat, visited, newX, newY, n)) {
        visited[newX][newY] = true; // Mark as visited
        ratInAMazeSolve(mat, visited, destX, destY, newX, newY, outputWay + "L", ans, n);
        visited[newX][newY] = false; // Backtrack
    }
    // Right
    newX = curX, newY = curY + 1;
    if (isSafe(mat, visited, newX, newY, n)) {
        visited[newX][newY] = true; // Mark as visited
        ratInAMazeSolve(mat, visited, destX, destY, newX, newY, outputWay + "R", ans, n);
        visited[newX][newY] = false; // Backtrack
    }
    // Up
    newX = curX - 1, newY = curY;
    if (isSafe(mat, visited, newX, newY, n)) {
        visited[newX][newY] = true; // Mark as visited
        ratInAMazeSolve(mat, visited, destX, destY, newX, newY, outputWay + "U", ans, n);
        visited[newX][newY] = false; // Backtrack
    }
    // Down
    newX = curX + 1, newY = curY;
    if (isSafe(mat, visited, newX, newY, n)) {
        visited[newX][newY] = true; // Mark as visited
        ratInAMazeSolve(mat, visited, destX, destY, newX, newY, outputWay + "D", ans, n);
        visited[newX][newY] = false; // Backtrack
    }
}


// Initializes and solves the Rat in a Maze problem
vector<string> ratInAMaze(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // Initialize visited matrix
    visited[0][0] = true; // Mark the start cell as visited
    vector<string> ans; // Store all valid paths

    if (mat[0][0] == 0) return ans; // If starting cell is blocked, return empty result

     
    // ratInAMazeSolve(mat, visited, n - 1, n - 1, 0, 0, "", ans, n);  // version 1
    ratInAMazeSolve_concised(mat, visited, n - 1, n - 1, 0, 0, "", ans, n); // version 2
    
    return ans; // Return all valid paths
}

int main()
{
    vector<vector<int>>mat{ 
        {1,0,0},
        {1,1,1,},
        {0,1,1}
      };
  
    auto ans = ratInAMaze(mat);
    for (auto way : ans) {
        cout << way<<endl;
    
    }
    return 0;
}
