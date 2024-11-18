#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/edit-distance/description/


// TC = O(3^(m+n) )  SC = O(m+n)
int solve(string &word1, string &word2, int i, int j) {
    // Base case 1: If we have traversed all characters of `word1`,
    // then the only way to make the strings equal is to insert the remaining characters of `word2`.
    if (i >= word1.size()) {
        return word2.size() - j; // Insert all remaining characters of `word2`.
    }

    // Base case 2: If we have traversed all characters of `word2`,
    // then the only way to make the strings equal is to delete the remaining characters of `word1`.
    if (j >= word2.size()) {
        return word1.size() - i; // Delete all remaining characters of `word1`.
    }

    // If the characters at `i` and `j` are different, we have 3 possible operations:
    if (word1[i] != word2[j]) {
        // 1. Insert a character at the current position in `word1` to match `word2[j]`.
        int option1 = 1 + solve(word1, word2, i, j + 1);

        // 2. Delete the current character of `word1` to continue with the rest.
        int option2 = 1 + solve(word1, word2, i + 1, j);

        // 3. Replace the current character of `word1` with `word2[j]`.
        int option3 = 1 + solve(word1, word2, i + 1, j + 1);

        // Return the minimum cost among the three operations.
        return min(option1, min(option2, option3));
    } else {
        // If the characters at `i` and `j` are already the same, no operation is needed.
        // Move to the next pair of characters in both strings.
        return 0 + solve(word1, word2, i + 1, j + 1);
    }
}

int main() {
    string word1 = "horse";
    string word2 = "ros";

    // Find the minimum edit distance starting from the first characters of both strings.
    cout << solve(word1, word2, 0, 0);

    return 0;
}
