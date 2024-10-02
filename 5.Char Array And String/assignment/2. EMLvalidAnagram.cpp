#include <algorithm>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/valid-anagram/description/

using namespace std;
// TC = O(nlogn), SC = O(1) - Sorting both strings and comparing them
bool isAnagram(string firstStr, string SecondStr) {
  if (firstStr.length() != SecondStr.length())
    return false;        
                 // Lengths must be equal
  sort(firstStr.begin(), firstStr.end()); // Sort both strings
  sort(SecondStr.begin(), SecondStr.end());

  for (int i = 0; i < firstStr.length(); i++) {
    if (firstStr[i] != SecondStr[i])
      return false; // Check sorted characters
  }
  return true; // Strings are anagrams
}

// TC = O(n), SC = O(n) - Using frequency array to count character occurrences 
// if both the frequency of characters in both array is same then its anagrams otherwise not 
// also works for unicode characters
bool isAnagram_OptimizedBySir(string firstStr, string SecondStr) {
  vector<int> freq(256, 0); // Frequency array for ASCII characters

  for (auto ch : firstStr) {
    freq[ch]++; // Count frequency of each char in first string
  }

  for (auto ch : SecondStr) {
    if (freq[ch] == 0)
      return false; // Extra char in second string
    freq[ch]--;     // Decrement freq for matching chars
  }

  for (auto elm : freq) {
    if (elm != 0)
      return false; // Remaining unmatched chars
  }

  return true; // Strings are anagrams
}

int main() {
  string firstStr = "anagram", SecondStr = "nagaram";

  cout << isAnagram_OptimizedBySir(firstStr, SecondStr);

  return 0;
}
