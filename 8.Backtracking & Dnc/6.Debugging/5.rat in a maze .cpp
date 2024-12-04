#include <iostream>
using namespace std;

// Prints the current state of the visited cells
void print(bool** visited, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Recursive function to explore paths in the maze
void solve(int maze[][4], bool** visited, int row, int col, int n) {
    // Base case: if out of bounds, return
    // if (row > n || col > n || row < 0 || col < 0) return;
    if (row >= n || col >= n || row < 0 || col < 0) return;
    
    // If the cell is already visited or not passable (0), return
    if (!(maze[row][col] && !visited[row][col])) return;

    // Mark the current cell as visited
    visited[row][col] = true;

    // If the destination cell is reached, print the path
    if (row == n - 1 && col == n - 1) {
        print(visited, n);
    }

    // Explore all four possible directions
    solve(maze, visited, row, col + 1, n); // Move right
    solve(maze, visited, row, col - 1, n); // Move left
    solve(maze, visited, row + 1, col, n); // Move down
    solve(maze, visited, row - 1, col, n); // Move up

    // Backtrack: unmark the current cell
    visited[row][col] = false;
}

// Initializes the visited array and starts the maze-solving process
void ratInAMaze(int maze[][4], int n) {
    // Dynamically allocate a 2D array for visited cells
    bool** visited = new bool*[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            visited[i][j] = false; // Initialize all cells as unvisited
        }
    }

    // Start solving from the top-left corner
    solve(maze, visited, 0, 0, n);
}

int main(int argc, char const *argv[]) {
    // Define the maze: 1 = passable, 0 = blocked
    int arr[][4] = { 
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1}
    };

    // Solve the maze
    ratInAMaze(arr, 4);
    return 0;
}
