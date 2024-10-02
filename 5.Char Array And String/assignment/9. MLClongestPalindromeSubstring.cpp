#include <iostream>
using namespace std;


// https://leetcode.com/problems/longest-palindromic-substring/

// Helper function to find the longest palindrome centered around indices `low` and `high`
string palindromeAroundIt(string &s, int low, int high) {
    // Expand the palindrome as long as the characters at `low` and `high` are equal
    // and within the bounds of the string
    while (low >= 0 && high < s.length() && s[low] == s[high]) {
        low--;  // Move left pointer outwards
        high++; // Move right pointer outwards
    }
    // Return the palindrome substring found, adjusting indices to correct bounds
    return s.substr(low + 1, high - low - 1);
}


// TC = O(N^2)  SC = O(N)
string longestPalindrome(string s) {
    string longest = ""; // Store the longest palindrome found

    // Loop through each character in the string
    for (int i = 0; i < s.length(); i++) {
        // Find longest palindrome with odd length (single center character)
        string oddLengthLongestPalindrome = palindromeAroundIt(s, i, i);
        // Find longest palindrome with even length (two center characters)
        string evenLengthLongestPalindrome = palindromeAroundIt(s, i, i + 1);

        // Update longest if odd-length palindrome is longer
        if (longest.length() < oddLengthLongestPalindrome.length()) {
            longest = oddLengthLongestPalindrome;
        }
        // Update longest if even-length palindrome is longer
        if (longest.length() < evenLengthLongestPalindrome.length()) {
            longest = evenLengthLongestPalindrome;
        }
    }

    return longest; // Return the longest palindrome substring
}


int main()
{
    
    cout << longestPalindrome("babad");
    return 0;
}
