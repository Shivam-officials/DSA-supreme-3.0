#include <corecrt.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    // Edge case: If numRows is 1, the zigzag pattern is just the original string.
    if (numRows == 1) return s;

    // Initialize a vector of strings to store each row of the zigzag pattern.
    vector<string> zigzag(numRows);

    // String to store the final answer after processing.
    string ans = "";

    // Index to keep track of the current position in the input string 's'.
    int i = 0;
    
    // Boolean to determine the direction of movement in the zigzag pattern.
    // 'true' means moving downward and 'false' means moving upward.
    bool direction = 1; 
    
    // Variable to track the current row we're filling in the zigzag pattern.
    int row = 0;
    
    // Infinite loop to iterate through the string.
    while (true) {
        if (direction) { // If moving downward (i.e., from top to bottom)
            // Move downwards by incrementing row until the bottom row is reached.
            while (i < s.size() && row < numRows) {
                zigzag[row++].push_back(s[i++]); // Append character to the current row and move to the next row
            }
            direction = !direction; // Change direction to upward
            row -= 2; // Adjust row to move back up (since it went one row beyond the limit)
        } else { // If moving upward (i.e., from bottom to top)
            // Move upwards by decrementing row until the top row is reached.
            while (i < s.size() && row >= 0) {
                zigzag[row--].push_back(s[i++]); // Append character to the current row and move to the previous row
            }
            row = 1; // Adjust row to move down again (starting from the second row)
            direction = !direction; // Change direction to downward
        }

        // Break out of the loop once we've processed all characters in the input string 's'.
        if (i >= s.size()) {
            break;
        }
    }

    // After constructing the zigzag pattern, combine all rows into a single string.
    for (auto str : zigzag) {
        ans += str; // Append each row to the final result.
    }

    return ans; // Return the result string.
}


int main() {
  string str = "paypalishiring";

  cout << convert(str, 3);
  return 0;
}
