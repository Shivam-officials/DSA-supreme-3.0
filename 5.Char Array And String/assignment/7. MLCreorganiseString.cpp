#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/reorganize-string/

// NOTE: when while(x--) we do then loop will be terminated when x = 0 bt the value after loop finished will be x = -1 

//IDEA: greedy appraoch only  think of the current issue 

// TC: = O(n) length of string 
// SC: =  O(k) OR O(1)., where k is the number of unique characters in the string. Given that k is bounded by the number of characters in the English alphabet, this can also be considered 
string reorganizeString_BYMEHashmap(string s) {
    unordered_map<char, int> count;
    
    // Find the most frequently occurring character and its frequency
    int maxOccuringElementCount = INT_MIN;
    char maxOccuringElement;
    for (auto ch : s) {
        count[ch]++;  // Count occurrences of each character
        // Update the most frequent character if necessary
        if (maxOccuringElementCount < count[ch]) {
            maxOccuringElementCount = count[ch];
            maxOccuringElement = ch;
        }
    }

    // Try placing the most frequent character at even indices (0, 2, 4, ...)
    int index = 0;
    while (count[maxOccuringElement]--) {
        // If it's impossible to reorganize, return an empty string
        if (index >= s.length()) {
            return "";
        }
        s[index] = maxOccuringElement;  // Place the most frequent character
        index += 2;
    }

    // Now place the remaining characters in the remaining slots
    count[maxOccuringElement] = 0;  // Reset count of the placed character
    for (auto &occurance : count) {
        // Place each character, switching to odd indices (1, 3, 5, ...) if even ones are filled
        while (occurance.second--) {
            index = (index >= s.length()) ? 1 : index;  // If even indices are finished, use odd indices
            s[index] = occurance.first;
            index += 2;
        }
    }

    return s;  // Return the reorganized string
}



string reorganizeString_CustomHash(string s) {
    int countOccurance[26] = {0};  // Custom hash to store frequency of each character (a-z)
    char maxOccuringElement;
    int maxOccuringElementCount = INT_MIN;

    // NOTE: In the custom hash, when inserting the value for a character, we subtract 'a' from the character to get its index.
    //       When retrieving the character from the hash, we add 'a' to the index to convert it back to the character.

    // Find the most frequent character and its frequency
    for (auto ch : s) {
        countOccurance[ch - 'a']++;  // Inserting into the custom hash by subtracting 'a' to get the correct index
        if (maxOccuringElementCount < countOccurance[ch - 'a']) {
            maxOccuringElement = ch;
            maxOccuringElementCount = countOccurance[ch - 'a'];
        }
    }

    // Place the most frequent character at every alternate index (0, 2, 4, ...)
    int index = 0;
    while (countOccurance[maxOccuringElement - 'a']--) {
        if (index >= s.length()) return "";  // If not enough space to place the character, return ""
        s[index] = maxOccuringElement;  // Place the most frequent character
        index += 2;
    }

    // Reset the frequency of the most frequent character to 0
    countOccurance[maxOccuringElement - 'a'] = 0;

    // Place the remaining characters
    for (int i = 0; i < 26; i++) {
        while (countOccurance[i]--) {
            index = (index >= s.length()) ? 1 : index;  // If even indices are filled, switch to odd indices
            s[index] = i + 'a';  // Retrieving the character from the custom hash by adding 'a' to the index
            index += 2;
        }
    }

    return s;
}


int main(int argc, char const *argv[])
{
    string str = "xogbmcjjie";
    cout<<reorganizeString_BYMEHashmap(str)<<endl;
    cout<<reorganizeString_CustomHash(str);

    return 0;
}
