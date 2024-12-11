#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// https://leetcode.com/problems/matchsticks-to-square/

// TC = O(4^N) SC = O(N)

// Function to check if matchsticks can form a square
bool checkPossible(vector<int> &matchSticks, int index, vector<int> &sides, int &sum4th) {
  // Base case: If any side exceeds the target length, return false
  if (sides[0] > sum4th || sides[1] > sum4th || sides[2] > sum4th || sides[3] > sum4th) {
    return false;
  }

  // If all matchsticks are used, check if all sides are equal
  if (index == matchSticks.size()) {
    return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
  }

  int currentElement = matchSticks[index];

  // Try placing the current matchstick on each side
  for (int i = 0; i < 4; i++) {
    sides[i] += currentElement; // Add to current side
    if (checkPossible(matchSticks, index + 1, sides, sum4th)) // Recursive call
      return true;
    sides[i] -= currentElement; // Backtrack
  }
  return false; // No valid placement found
}

// Main function to determine if matchsticks can form a square
bool makeSquare(vector<int> &matchSticks) {
  int sum = accumulate(matchSticks.begin(), matchSticks.end(), 0); // Total length of matchsticks
  int sum4th = sum / 4; // Target length for each side

  // If the total length is not divisible by 4, return false
  if (sum % 4 != 0) {
    return false;
  }

  vector<int> sides(4, 0); // Initialize sides of the square with 0

  // Sort matchsticks in decreasing order for optimization TO ESCAPE EXTRA RECURSIVE CALLS
  sort(matchSticks.rbegin(), matchSticks.rend());

  return checkPossible(matchSticks, 0, sides, sum4th);
}

int main() {
  vector<int> matchSticks{1, 1, 2, 2, 2}; // Example input: true
  // vector<int>matchSticks{3,3,3,3,4}; // Example input: false
  cout << makeSquare(matchSticks);
  return 0;
}
