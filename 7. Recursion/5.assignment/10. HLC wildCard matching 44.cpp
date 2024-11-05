// https://leetcode.com/problems/wildcard-matching/description/

/** Question
    Given an input string (s) and a pattern (p), implement wildcard pattern
   matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).



    Example 1:

    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    Example 2:

    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.
    Example 3:

    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not
   match 'b'.

*/

#include <iostream>
using namespace std;

// TC = O(2^N) SC = O(N)  where N = chars in input string (s) according to sir muje to aaya ni tha pura dhang se TC ...SC aa gya tha
bool isMatchHelper(string &s, int si, string &p, int pi) {

  // If both strings are fully matched
  if (si == s.size() && pi == p.size()) return true;

  // If pattern has remaining characters but string is empty
  if (si == s.size()) {
    while (pi < p.size()) {
      if (p[pi] != '*') return false;
      pi++;
    }
    return true;
  }

  // If characters match or pattern has '?'
  if (s[si] == p[pi] || p[pi] == '?') {
    return isMatchHelper(s, si + 1, p, pi + 1);
  }

  // If pattern has '*', consider two cases:
  if (p[pi] == '*') {
    // Case A: '*' matches no characters
    bool caseA = isMatchHelper(s, si, p, pi + 1);
    // Case B: '*' matches one character
    bool caseB = isMatchHelper(s, si + 1, p, pi);
    return caseA || caseB;
  }

  // Characters do not match
  return false;
}


int main(int argc, char const *argv[]) {
  string s = "abcdefg", p = "abc*fg";

    
  cout << isMatchHelper(s, 0, p, 0);
  return 0;
}
