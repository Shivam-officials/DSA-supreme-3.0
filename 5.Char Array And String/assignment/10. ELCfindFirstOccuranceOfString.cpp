#include <iostream>
#include <string>
using namespace std;


// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/


// TC = O(n * m) n = haystack size , m = needle size
// Sc = O(1)

/**
  **Intution explanation: Sliding Window Search: Loop through haystack and try to match needle starting from each index. When a character in haystack matches the first character of needle, the program checks if the rest of the characters match by incrementing both the haystack and needle pointers (i and j).
 */
int strStr(string &haystack, string &needle) {
    // If needle is longer than haystack, return -1 as it cannot be found
    if (needle.length() > haystack.length()) return -1;
    
    int ans = -1;        // Store the starting index of the matching substring

    // Iterate over the haystack string
    for (int i = 0; i < haystack.length(); i++) {
        int j = 0; // Reset j for each new check

        // If the current character matches the first character of needle
        if (haystack[i] == needle[j]) {
            ans = i; // Possible match starting at index i
            
            // Check if the rest of the needle matches the substring in haystack
            while (i + j < haystack.length() && haystack[i + j] == needle[j] && j < needle.length()) {
                j++; // Increment j to compare the next character
            }

            // If the entire needle matches, return the starting index
            if (j == needle.length()) return ans;

            // If not a complete match, reset answer to -1
            ans = -1;
        }
    }

    return ans; // If no match is found, return -1
}


int byDefualtMethod(string heystack, string needle){
    int ans = -1;
    for (int i = 0; i < heystack.length(); i++) {
        string currentString = heystack.substr(i,needle.length());
        if(currentString ==needle) return i;
    }
    return -1; 
}

int main(){
    
    string hystck = "sadbutsad", nidle = "sad";
    cout << strStr(hystck, nidle)<<endl;
    cout << byDefualtMethod(hystck, nidle)<<endl;
    return 0;
}

