#include <iostream>
#include <vector>
using namespace std;

// only works for 3
string removeAllAdajcentElement_ME_notGeneric(string &s, int k) {
  string str = "";
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    int strlastIndex = str.length() > 0 ? str.length() - 1 : 0;

    /**  if (str.empty()) {
         str.push_back(s[i]);
     }else */
    if ((strlastIndex >= 1) && (s[i] == str[strlastIndex]) &&
        (s[i] == str[strlastIndex - 1])) {
      str.pop_back();
      str.pop_back();
    } else {
      str.push_back(s[i]);
    }
    cout << str << " str at the " << i << "th iteration" << endl;
  }
  return str;
}



/**
 * @brief Checks if the last 'k' characters in string 's' match character 'c'.
 * 
 * @param s The reference string to check.
 * @param c The character to match.
 * @param k The number of characters to compare.
 * @return true if the last 'k' characters in 's' are equal to 'c', false otherwise.
 * 
 * @note The function starts from the last index of the string and compares
 * the last 'k' characters with 'c'. If they match, it returns true; otherwise, false.
 * Time complexity: O(k) for each call.
 */
bool matchingLastKElementCOrNot_ME(string &s, char c, int k) {
  int lastIndex = s.length() - 1;
  
  // If the string length is smaller than 'k', it can't match the last k elements.
  if (s.length() < k)
    return false;
  
  // Check the last 'k' characters one by one to see if they match 'c'.
  while (k--) {
    if (s[lastIndex] == c) {
      lastIndex--;  // Move to the previous character
    } else {
      return false;  // Mismatch found, return false
    }
  }

  return true;  // All characters matched
}

/**
 * @brief Removes all adjacent duplicate characters if their count reaches 'k'.
 * 
 * @param s The input string to process.
 * @param k The number of adjacent duplicates to trigger removal.
 * @return string The processed string after all adjacent duplicates of length 'k' are removed.
 * 
 * @note The function iterates over the input string 's' and uses a temporary string 'str' to simulate a stack.
 * It checks the last 'k-1' characters in the temporary string and pops them if the next character matches.
 * Time complexity: O(n * k), Space complexity: O(n).
 */
string removeAllAdajcentElement_ME_NotOptimised(string &s, int k) {
  string str = "";  // Temporary string to simulate a stack
  int counter = k - 1;
  
  // Loop over the input string 's'.
  for (int i = 0; i < s.length(); i++) {
    
    // If the stack is empty, push the current character.
    if (str.empty()) {
      str.push_back(s[i]);
    } 
    // Check if the last 'k-1' characters in the stack match the current character.
    else if (matchingLastKElementCOrNot_ME(str, s[i], k - 1)) {
      
      // If they match, pop the last 'k-1' characters from the stack.
      for (int i = 0; i < k - 1; i++) {
        str.pop_back();
      }

    } 
    // If no match, push the current character onto the stack.
    else {
      str.push_back(s[i]);
    }
  }
  
  return str;  // Return the resulting string after all possible removals
}

int main() {
  string str = "deeedbbcccbdaa";

    cout << removeAllAdajcentElement_ME_NotOptimised(str,3);

  return 0;
}
