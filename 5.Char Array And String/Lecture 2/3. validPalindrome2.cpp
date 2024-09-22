// https://leetcode.com/problems/valid-palindrome-ii/


#include <iostream>
#include <vector>
using namespace std;

/**
 * @note INTUITION:
 * FACT : Every palindrome can be checked by choosing a center and expanding outward symmetrically, 
 * comparing characters from the left and right.
 *
 * If we find a mismatch while shrinking the window , we can check if the substring becomes a palindrome 
 * either by skipping the left (start + 1) or the right (end - 1) character. 
 * The idea is to verify if we can make the string a palindrome by removing at most one character.
 */


// Helper function to check if a substring (from index 'start' to 'end') is a palindrome
bool palindromeOrNot(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {  // If characters don't match, it's not a palindrome
            return false;
        }
        start++;
        end--;
    }
    return true;  // If all characters match, it's a palindrome
}

// Main function to check if the string is a valid palindrome (or becomes one after removing at most one character)
bool validPalindrome(string s) {
    int start = 0;
    int end = s.length() - 1;

    // Loop to compare characters from both ends of the string
    while (start < end) {
        if (s[start] == s[end]) {  // If characters match, move inward
            start++;
            end--;
        } else {
            // If a mismatch is found, check if removing either character (start or end) leads to a palindrome
            return palindromeOrNot(s, start, end - 1) || palindromeOrNot(s, start + 1, end);
        }
    }

    return true;  // The string is already a palindrome if no mismatches are found
}


int main() {
  string str = "rabbcar";
  if(validPalindrome(str))
  {
    cout << "it can be valid palidrom";
  }else 
  {
    cout << "its can't not a valid palimdrom ";
  }
  

  return 0;
}
