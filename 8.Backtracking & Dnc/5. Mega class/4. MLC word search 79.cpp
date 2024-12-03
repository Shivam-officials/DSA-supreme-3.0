#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/word-search/

// TC = O(m.n.4^k) SC = O(m.n)

// Check if the new coordinates are within bounds and unvisited
bool isSafe(int newX, int newY, vector<vector<bool>> &visited) {
  if (newX < 0 || newX >= visited.size() || newY < 0 ||
      newY >= visited[0].size() || visited[newX][newY] == true) {
    return false;
  }
  return true;
}

// Recursively search for the word in all 4 directions
bool wordSearch(int curX, int curY, string &word, int index,
                vector<vector<char>> &grid, vector<vector<bool>> &visited) {

  // Base case: if we've found the word completely
    // every index is checked that the word matched at the current coordinates
    // with current index already so if index is at last of word that means we
    // found the words bcz bina check kiye to ayega ni is index pe word

  if (index == word.size() - 1) {
    return true;
  }

  // Direction vectors: Right, Down, Left, Up
  vector<int> dx{0, 1, 0, -1};
  vector<int> dy{1, 0, -1, 0};

  bool surroundExist = false;
  // Explore all 4 directions
  for (int i = 0; i < 4; i++) {
    int newX = curX + dx[i];
    int newY = curY + dy[i];
    if (isSafe(newX, newY, visited) && grid[newX][newY] == word[index + 1]) {
      visited[newX][newY] = true;
      bool ans = wordSearch(newX, newY, word, index + 1, grid, visited);
      visited[newX][newY] = false;
      surroundExist = surroundExist || ans;  // Keep track if word exists in any direction
    }
  }
  return surroundExist;
}

// Main function to check if word exists in the grid
bool exist(vector<vector<char>> &grid, string &word) {
  int m = grid.size(), n = grid[0].size();
  bool exist = false;
  
  // Start from every cell to find potential start for word
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == word[0]) {  // If first character matches
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[i][j] = true;
        bool ans = wordSearch(i, j, word, 0, grid, visited);
        exist = ans || exist;  // If word is found, no need to check further
      }
    }
  }
  return exist;
}


int main() {
  vector<vector<char>> grid = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  //   {
  //     {'b', 'b', 'a', 'a', 'b', 'a'},
  //     {'b', 'b', 'a', 'b', 'a', 'a'},
  //     {'b', 'b', 'b', 'b', 'b', 'b'},
  //     {'a', 'a', 'a', 'b', 'a', 'a'},
  //     {'a', 'b', 'a', 'a', 'b', 'b'}
  //   };

  string word = "SEE";
  //   string word = "abbbababaa"; // TLE

  cout << exist(grid, word);

  return 0;
}
