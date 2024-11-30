#include <iostream>
#include <string>
#include <vector>
using namespace std;

//all test cases pass
bool isSafe(int newX, int newY, vector<vector<bool>> &visited) {
  if (newX < 0 || newX >= visited.size() || newY < 0 ||
      newY >= visited[0].size())
    return false;

  if (visited[newX][newY] == true) {
    return false;
  } else {
    return true;
  }
}

bool wordSearch(int curX, int curY, string &word, int index,
                vector<vector<char>> &grid, vector<vector<bool>> &visited) {

  if (curX >= grid.size() || curX < 0 || curY >= grid[0].size() || curY < 0) {
    return false;
  }

  // cout << curX << " " << curY << endl;

  if (index == word.length() - 1) {
    // cout << "the current word is " << currentWord << endl;
    return true;
  }
  vector<int> dx{0, 0, -1, 1};
  vector<int> dy{-1, 1, 0, 0};
  bool ans = false;
  for (int i = 0; i < 4; i++) {
    int newX = curX + dx[i];
    int newY = curY + dy[i];

    if (isSafe(newX, newY, visited)) {
      visited[newX][newY] = true;
      //   currentWord.push_back(grid[newX][newY]);
      bool option1 = false;
      if (grid[newX][newY] == word[index + 1]) {
        option1 = wordSearch(newX, newY, word, index + 1, grid, visited);
      }

      visited[newX][newY] = false;
      //   currentWord.pop_back();

      ans = ans || option1;
    }
  }
  // currentWord.pop_back();
  return ans;
}
bool exist(vector<vector<char>> &grid, string word) {
  int m = grid.size(), n = grid[0].size();
  bool option1 = false;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == word[0]) {

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[i][j] = true;

        bool ans = wordSearch(i, j, word, 0, grid, visited);
        option1 = option1 || ans;
      }
    }
  }

  return option1;
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
