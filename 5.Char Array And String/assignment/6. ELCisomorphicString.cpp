#include <iostream>
#include <unordered_map>
using namespace std;


// https://leetcode.com/problems/isomorphic-strings/

// Function to normalize a string by mapping each unique character 
// to a new character starting from 'a'.
void normalise(string &s) {
  unordered_map<char, char> mapping;
  char start = 'a';  // Start mapping from 'a'
  
  // Create the mapping for unique characters
  for (auto ch : s) {
    if (mapping.find(ch) == mapping.end()) {
      mapping[ch] = start++;
    }
  }

  // Replace characters in the original string with their mapped values
  for (auto &ch : s) {
    ch = mapping[ch];
  }
}

// Check if two strings are isomorphic using normalization
bool isIsomorphic(string s, string t) {
  if (s.length() != t.length())  // Lengths must be equal
    return false;
  
  normalise(s);  // Normalize both strings
  normalise(t);
  
  return s.compare(t) == 0;  // Check if normalized strings are equal
}

// Check if two strings are isomorphic using direct mapping
bool isIsomorphic_bySir(string s, string t) {
  int n = s.size();
  int m1[256] = {0}, m2[256] = {0};  // Arrays to store character mappings

  // Traverse both strings
  for (int i = 0; i < n; i++) {
    if (m1[s[i]] != m2[t[i]])  // Mappings must match
      return false;
    
    // Update mappings with the current index + 1
    m1[s[i]] = i + 1;
    m2[t[i]] = i + 1;
  }

  return true;  // Strings are isomorphic
}


int main(int argc, char const *argv[])
{
    string s = "add",t = "egg";
    cout << ( isIsomorphic(s, t) ? "is isomorphic": "not isomorphic");
    return 0;
}
