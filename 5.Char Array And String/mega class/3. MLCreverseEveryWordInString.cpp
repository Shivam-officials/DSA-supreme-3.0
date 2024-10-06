#include <algorithm>
#include <iostream>
using namespace std;



// https://leetcode.com/problems/reverse-words-in-a-string/


/** @note  TC = 3 * O(N) = O(N)::: bcz we processod each character once and reversing the
 // entire array will also be O(N) and for every word reverse the most character
 // a word can hold is equal to the length of string so reversing that would also
 // be O(N) thus 3*O(N) = O(N) SC = O(1)
*/
// SC = O(1)

string reverseWords_ME(string s) {
  // Reverse the entire string first
  reverse(s.begin(), s.end());

  int i = 0, start = 0,
      end = 0; // Initialize index pointers for start, end of words

  // Iterate through the entire string
  while (i < s.length()) {

    // Skip any leading spaces between words
    while (i < s.length() && s[i] == ' ') {
      i++; // Increment index to bypass spaces
    }

    // out of bound check and exit
    if (i == s.length()) {
      break;
    }

    // Process the current word and store it starting from 'end' position
    while (i < s.length() && s[i] != ' ') {
      s[end++] = s[i++]; // Copy non-space characters (the word) to their new position
    }

    // Reverse the current word to correct its order
    reverse(s.begin() + start, s.begin() + end);

    // After reversing, add a space to separate the words
    s[end++] = ' ';

    // Set 'start' to the current 'end' for the next word
    start = end;
  }

  // Resize the string to remove any trailing spaces
  s.resize(end - 1); // The last space added above is trimmed off
  return s;          // Return the final result string
}

string reverseWords_SirSameLogicBtEasyWriting(string s) {

  reverse(s.begin(), s.end());
  int n = s.size();
  int start = 0, end = 0;

  for (int i = 0; i < n; i++) {
    // skip leading spaces
    while (i < n && s[i] == ' ')
      i++;
    if (i == n)
      break; // out of bound check

    // copy char to the right position
    while (i < n && s[i] != ' ')
      s[end++] = s[i++];

    // after copy reverse the individual word
    reverse(s.begin() + start, s.begin() + end);

    // add extra space between word
    s[end++] = ' ';
    start = end;
  }

  // resize the final string.
  s.resize(end - 1);
  return s;
}

int main() {
  string str1 = " Hello world  ";
  string str2 = "a good   example";

  //   cout << reverseWords(str1) ;
  //   cout << reverseWords_SirSameLogicBtEasyWriting(str2);
  cout << reverseWords_ME(str1);
  return 0;
}
