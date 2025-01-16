#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

/** Intuition: Generate all subsequences of the input string (ignoring order),
    then for each subsequence, calculate all permutations to get all possible
    unique arrangements of tiles.
*/
void subSequence(string tiles, set<string> &ansSet, string outputStr, int index) {
  // Base Case: If we've reached the end of the input string
  if (index == tiles.length()) {
    ansSet.insert(outputStr); // Insert the generated subsequence into the set
    return;
  }

  // Include the current character in the subsequence
  subSequence(tiles, ansSet, outputStr + tiles[index], index + 1);

  // Exclude the current character and move to the next index
  subSequence(tiles, ansSet, outputStr, index + 1);
}

/*
Intuition: Generate all permutations of a given string (order matters) while
handling duplicates by using a map to track which characters have been used
at the current level of recursion.
*/
void permutations(string &tiles, set<string> &ans, int index) {
  // Base Case: If the permutation is complete
  if (index == tiles.length()) {
    ans.insert(tiles); // Add the permutation to the set
    return;
  }

  unordered_map<char, bool> map; // To avoid duplicate swaps at the same level

  // Iterate over the remaining characters
  for (int i = index; i < tiles.length(); i++) {
    // Skip if the character has already been processed at this level
    if (map.find(tiles[i]) != map.end())
      continue;

    // Mark the character as used
    map[tiles[i]] = true;

    // Swap the current character to the current position
    swap(tiles[i], tiles[index]);

    // Recurse for the next position
    permutations(tiles, ans, index + 1);

    // Backtrack by swapping back
    swap(tiles[i], tiles[index]);
  }
}

/*
Approach: Combines subsequences and permutations to calculate all possible
tile arrangements. This approach generates subsequences first, then calculates
permutations for each subsequence.
*/
int numTilePossibilities(string tiles) {
  set<string> ans; // Set to store unique subsequences
  subSequence(tiles, ans, "", 0); // Generate all subsequences

  set<string> realAns; // Set to store all unique permutations
  for (auto elm : ans) {
    permutations(elm, realAns, 0); // Generate permutations for each subsequence
  }

  // Uncomment to print all unique permutations
  // for (auto elm : realAns) {
  //   cout << elm << endl;
  // }

  return realAns.size()-1; // Return the total number of unique permutations
}

/*
Optimized Approach: Directly calculate all possible unique tile arrangements
using backtracking and a frequency map to handle duplicate characters.
*/
void allPossibleArrangement(unordered_map<char, int> &count, int &result) {
  // Recursive exploration of arrangements
  for (auto &pair : count) {
    if (pair.second > 0) { // If the character is still available
      result++; // Count this arrangement
      pair.second--; // Use one occurrence of the character
      allPossibleArrangement(count, result); // Recurse for the remaining tiles
      pair.second++; // Backtrack: restore the character count
    }
  }
  return;
}

void numTilePossibilities2(string tiles) {
  unordered_map<char, int> count; // Frequency map for input characters
  for (auto elm : tiles) {
    count[elm]++; // Count each character
  }

  int result = 0;
  allPossibleArrangement(count, result); // Calculate unique arrangements
  cout << result; // Print the total number of possibilities
}

int main(int argc, char const *argv[]) {
  // Method 1: Using subsequences + permutations
//   cout << numTilePossibilities("AAB")<<endl; //TC = O(2^k.K!) 

  // Method 2: Optimized approach using backtracking and frequency map
  numTilePossibilities2("AAB"); // TC = O(k.k!) Sc = O(k+k!) //!didnt know how this is complexity acc. to current knowledge

  return 0;
}
