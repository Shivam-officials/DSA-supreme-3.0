// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// TC = O(n^2)  Sc= O(1)
int beautySumWithMap(string s) {
  // Initialize beautySum to store the cumulative beauty of all substrings
  int beautySum = 0;

  // Outer loop to traverse each starting character of the substring
  for (int i = 0; i < s.length(); i++) {

    // Use an unordered_map to store the frequency of characters in the
    // substring
    unordered_map<char, int> mp;

    // Inner loop to build substrings starting from 'i' to the end of the string
    for (int j = i; j < s.length(); j++) {

      // Increment the frequency of the current character in the map
      mp[s[j]]++;

      // Initialize mini and maxi to store the minimum and maximum frequency in
      // the current substring
      int mini = INT_MAX; // Smallest frequency
      int maxi = INT_MIN; // Largest frequency

      // Traverse the frequency map to find the minimum and maximum frequencies
      for (auto entry : mp) {
        mini = min(
            mini,
            entry.second); // Update mini if the current frequency is smaller
        maxi =
            max(maxi,
                entry.second); // Update maxi if the current frequency is larger
      }

      // Add the difference (maxi - mini) to beautySum for the current substring
      beautySum += maxi - mini;
    }
  }

  // Return the total beauty sum for all substrings
  return beautySum;
}

// TC = O(n^2) SC = O(1) // same logic bt faster bcz of no overhead of hash, buckets etc
int beutySumWithCustomHash_optimised(string s) {
    int beutySum = 0;

    // Outer loop to traverse each starting index of the substring
    for (int i = 0; i < s.length(); i++) {
        // Hash array to store the frequency of each character
        int hash[26] = {0};

        // Inner loop to form substrings starting from index i
        for (int j = i; j < s.length(); j++) {
            // Increment frequency of the current character
            hash[s[j] - 'a']++;

            int mini = INT_MAX;
            int maxi = INT_MIN;

            // Calculate the minimum and maximum frequency from the hash array
            for (auto count : hash) {
                if (count > 0) { // Only consider characters that are present
                    maxi = max(maxi, count);  // Find the maximum frequency
                    mini = min(mini, count);  // Find the minimum frequency
                }
            }

            // Add the difference between max and min frequency to beautySum
            beutySum += maxi - mini;
        }
    }

    // Return the total beauty sum of all substrings
    return beutySum;
}


int main() {
  cout << beautySumWithMap("aabcbaa") << endl;
    cout << beutySumWithCustomHash_optimised("aabcbaa")<<endl;
  return 0;
}
