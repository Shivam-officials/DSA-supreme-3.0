#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;


// https://leetcode.com/problems/group-anagrams/description/

void showVectorMatrix(vector<vector<string>> v) {
  int rows = v.size();
  int cols = v[0].size();
  cout << endl;
  for (auto row : v) {
    for (auto elm : row) {
      cout << elm << " ";
    }
    cout << endl;
  }
}

// TC = O(n * m log m) SC = O(n*m) // n is the number of strings. & m is the average length of the strings.
vector<vector<string>> groupAnagrams_ME_BruteFOrce(vector<string> &strs) {
       unordered_map<string,vector<string>> mp;
       for(auto str:strs){
        string sortedStr = str;
        sort(sortedStr.begin(),sortedStr.end());
        mp[sortedStr].push_back(str);
       } 

       vector<vector<string>> ans;
       for(auto pr:mp){
        ans.push_back(pr.second);
       }

       return ans;
}


// Time Complexity: O(n * k log k), where n is the number of strings, k is the average length of the strings
// Space Complexity: O(n * k), for storing the strings and hash map
// ignoring map complexities for now for future
vector<vector<string>> groupAnagram_sir_SortAndHashMap(vector<string> &strs) {
    // HashMap to store sorted strings as keys and original strings as values (grouped anagrams)
    unordered_map<string, vector<string>> anagramGroupsTable;

    // For each string, sort it and use the sorted string as the key
    for (auto ch : strs) {
        string s = ch;
        sort(s.begin(), s.end()); // Sort string -> O(m log m), m is average string length
        anagramGroupsTable[s].push_back(ch); // Insert original string -> O(1) average
    }

    // Build the result vector of grouped anagrams
    vector<vector<string>> ans;
    for (auto it : anagramGroupsTable) {
        ans.push_back(it.second); // Add each group to the result -> O(n)
    }

    return ans;
}


array<int, 256> makeFrequencyTable(const string& s) {
    array<int, 256> frequencyTable = {0}; // Initialize frequency table
    for (auto ch : s) {
        frequencyTable[ch]++; // Increment frequency for each character
    }
    return frequencyTable; // Return the frequency table
}


// TC = O(n*k) SC = O(n*K)+mapsize too bt we ignore map for now bcz of lack of course coverage
vector<vector<string>> groupAnagram_sir_WithOutSortAndHashMap_BestOptimized(vector<string>& strs) {
    // Map to store frequency tables as keys and corresponding anagrams as values
    map<array<int, 256>, vector<string>> anagramGroupsTable;

    // Populate the map with frequency tables as keys
    for (auto currentWord : strs) {
        anagramGroupsTable[makeFrequencyTable(currentWord)].push_back(currentWord); // Group anagrams
    }

    // Prepare the result vector of grouped anagrams
    vector<vector<string>> ans;
    for (auto it : anagramGroupsTable) {
        ans.push_back(it.second); // Add each anagram group to the result
    }

    return ans; // Return the grouped anagrams
}


int main() {
  vector<string> stringArrya{"eat", "tea", "tan", "ate", "nat", "bat"};

  // showVectorMatrix(groupAnagram_sir_WithOutSortAndHashMap_BestOptimized(stringArrya));
  string str = "okayji";
  str.substr(1,0);
   
  return 0;
}
