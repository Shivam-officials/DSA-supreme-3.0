#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

// Recursive function to generate letter combinations
//!TC = after DP try to find out now
void letterCombinationSolve(string &digits, string output, int index, unordered_map<char,string> &map, vector<string> &ans) {
    // Base case: when index reaches the end of the digits
    if (index >= digits.size()) {
        ans.push_back(output); // Add the current combination to result
        return;
    }
    
    // Get the mapped characters for the current digit
    string mappedString = map[digits[index]];

    // Recur for each character in the mapped string
    for (int i = 0; i < mappedString.length(); i++) {
        letterCombinationSolve(digits, output + mappedString[i], index + 1, map, ans);
    }
}

// Main function to find all letter combinations for a given set of digits
vector<string> letterCombinations(string &digits, vector<string>& ans) {
    // Mapping of digits to corresponding letters
    unordered_map<char, string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";

    if (digits == "") return ans; // Return empty if input is empty
    
    // Start recursive function to find combinations
    letterCombinationSolve(digits, "", 0, map, ans);
    return ans; // Return the result
}

int main() {
    string digits = "23";  // Input digits

    vector<string> ans;
    // Print all the combinations in ans
    for (auto elm : ans) {
        cout << elm << endl;
    }
    return 0;
}
