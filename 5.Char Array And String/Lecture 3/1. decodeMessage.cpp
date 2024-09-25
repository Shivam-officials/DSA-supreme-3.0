//  https://leetcode.com/problems/decode-the-message/description/

#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

// TC = O(n)
string decodeMessage(string key, string message) {

  unordered_map<char, char> hash;
  string letters = "abcdefghijklmnopqrstuvwxyz";
  int mapIndex = 0;

  // Build the mapping based on the key string
  for (int i = 0; i < key.length(); i++) {
    // Only map non-space characters and avoid duplicate mappings
    if (key[i] != ' ' && hash.find(key[i]) == hash.end()) {
      hash.insert(make_pair(key[i], letters[mapIndex++])); // Assign the next unused letter
    }
  }

  string ans;
  
  // Decode the message using the generated mapping
  for (auto ch : message) {
    if (ch == ' ') { 
      ans.push_back(' '); // Preserve spaces in the message
    } else {
      ans.push_back(hash[ch]); // Map and decode the characters
    }
  }
  
  return ans; // Return the decoded message
}


int main() {
  cout << decodeMessage("the quick brown fox jumps over the lazy dog",
                        "vkbs bs t suepuv");

  return 0;
}
