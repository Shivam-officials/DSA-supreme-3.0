#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @intution:  
    The idea is to traverse through the array and keep a count of consecutive identical characters.
    If we encounter a different character, we append the character and its count (if greater than 1) to the original array.
    We continue this process until we have processed all characters, thus compressing the array in place.
 */

//RUN LENGTH ENCODING

// works bt with a lot of  0(N) space complexity
// SC = O(N) TC = O(N);
int compress_ME(vector<char> &chars) {
    int adjacentCount = 1;  // Tracks consecutive character count
    vector<char> ans;       // Resultant compressed string

    for (int i = 0; i < chars.size() - 1; i++) {
        // If the current and next characters are the same, increase count
        if (chars[i] == chars[i+1]) {
            adjacentCount++;
            continue;  // Skip further processing until a different char is found
        }

        // Build the current group of characters with their count if > 1
        string currentGp = "";
        if (adjacentCount == 1) {
            currentGp.push_back(chars[i]);  // Add character directly if no repetition
        } else {
            currentGp.push_back(chars[i]);  // Add character
            currentGp.append(to_string(adjacentCount));  // Append count to it
        }

        // Append current group to the answer vector
        for (auto ch : currentGp) {
            ans.push_back(ch);
        }

        // Reset count for the next group
        adjacentCount = i != chars.size() - 1 ? 1 : adjacentCount;
    }

    // Process the last character and its count
    ans.push_back(chars[chars.size()-1]);
    string adjacentCountString = to_string(adjacentCount);

    int j = 0;
    // Append the count of the last group if > 1
    while (adjacentCount > 1 && j < adjacentCountString.length()) {
        ans.push_back(adjacentCountString[j++]);
    }

    // Debug print for the final compressed characters
    for (auto ch : ans) {
        cout << ch;
    }

    // Swap the compressed result back to the original vector
    chars.swap(ans);
    
    // Return the new size of the compressed array
    return chars.size();
}

// TC = O(N) SC = O(N)
int compress_Sir(vector<char> &chars) {
    int adjacentCount = 1;  // Tracks the number of consecutive identical characters
    int index = 0;          // Index to place the compressed characters in the original array

    // Iterate through the array, except for the last character
    for (int i = 0; i < chars.size() - 1; i++) {
        // If the current character matches the next one, increment adjacentCount
        if (chars[i] == chars[i + 1]) {
            adjacentCount++;
            continue;  // Continue without processing until a different character is found
        }

        // Add the current character to the compressed position in the array
        chars[index++] = chars[i];

        // If the adjacentCount is more than 1, add the count as well
        if (adjacentCount > 1) {
            // Convert the count to string and append each digit to the array
            for (auto ch : to_string(adjacentCount)) {
                chars[index++] = ch;
            }
        }

        // Reset adjacentCount for the next group of characters
        adjacentCount = 1;
    }

    // Add the last character (since the loop doesn't include the last one)
    chars[index++] = chars[chars.size() - 1];

    // Append the count for the last character group if greater than 1
    if (adjacentCount > 1) {
        for (auto ch : to_string(adjacentCount)) {
            chars[index++] = ch;
        }
    }

    // Return the new size of the compressed array
    return index;
}

// TC = O(N) SC = O(1);
int compress_LeetcodeCopy(vector<char>& chars) {
    int index = 0;  // Index to place the compressed characters in the original array

    // Iterate through the characters in the input array
    for (int i = 0; i < chars.size();) {
        char letter = chars[i];  // Store the current character
        int count = 0;           // Initialize count of consecutive characters

        // Count how many times the current character appears consecutively
        while (i < chars.size() && chars[i] == letter) {
            count++;  // Increment the count for the current character
            i++;      // Move to the next character
        }

        // Place the character at the current index in the compressed position
        chars[index++] = letter;

        // If the count of consecutive characters is greater than 1,
        // convert the count to a string and append each digit to the array
        if (count > 1) {
            for (auto ch : to_string(count)) {
                chars[index++] = ch;  // Append each digit of the count
            }
        }
    }

    // Intuition: The index now represents the new size of the compressed array.
    // Return the length of the compressed string.
    return index;  // The index is already incremented +1 for the character being processed
}


int main() {
  vector<char> ch{'a', 'a', 'b', 'b', 'c','c','c','c','c','c','c','c', 'c', 'c',};
//   vector<char> ch{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
  // cout << compress(ch);
  cout << compress_Sir(ch)<<endl;
  for (auto ch : ch) {
    cout << ch;
  }
 
  return 0;
}


