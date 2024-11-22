#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/permutations/

//TC = O(N!) SC = O(N) bcz we are not storing anything so its just recursion stack memory used here 

// Recursive function to print all permutations of a string
void printAllPermutationsForString(string &input, int i) {
    // Base case: if the entire string is traversed, print the current permutation
    if (i == input.size()) {
        cout << input << endl;
        return;
    }

    // Recursive case: swap each character with the current position and explore
    for (int j = i; j < input.size(); j++) {
        swap(input[i], input[j]); // Swap current character with the position i
        printAllPermutationsForString(input, i + 1); // Recurse for the next index
        swap(input[i], input[j]); // Backtrack to restore original string
    }
}


//TC = O(N!) SC = O(N! * N) for storing result

// Recursive function to generate all permutations of a vector
void printAllPermutationsForVector(vector<int> &input, int i, vector<vector<int>> &ans) {
    // Base case: if the entire vector is traversed, add the current permutation to ans
    if (i == input.size()) {
        ans.push_back(input);
        return;
    }

    // Recursive case: swap each element with the current position and explore
    for (int j = i; j < input.size(); j++) {
        swap(input[i], input[j]); // Swap current element with position i
        printAllPermutationsForVector(input, i + 1, ans); // Recurse for the next index
        swap(input[i], input[j]); // Backtrack to restore original vector
    }
}

int main() {
    // Input string and vector
    string input = "abc";
    vector<int> num{1, 2, 3,4};

    // Print all permutations of the string
    printAllPermutationsForString(input, 0);
    cout << endl;

    // Generate and print all permutations of the vector
    vector<vector<int>> ans;
    printAllPermutationsForVector(num, 0, ans);

    // Print the generated vector permutations
    for (auto permutation : ans) {
        for (auto element : permutation) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}
