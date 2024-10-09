#include <algorithm> // Include for STL algorithms like replace
#include <cstring>   // Include for C-style string functions like strlen
#include <iostream>  // Include for standard input/output
#include <string>
#include <vector>    // Include for using vectors, though not used here

using namespace std; // Use standard namespace

// Function to print elements of a character array
void printElement(char a[]) {
    int len = strlen(a); // Get the length of the string
    cout << "The length is " << len; // Print the length

    // Loop through the array and print each character, including null terminator
    for (int i = 0; i < len + 1; i++) {
        cout << a[i] << endl; // Print each character
    }
}

// Function to replace a specified character in a char array
void cinReplaceChar(char ch[100], char originalChar, char replacementChar, int length) {
    for (int i = 0; i < length; i++) { // Iterate through the array
        if (ch[i] == originalChar) { // Check if the current character is the one to replace
            ch[i] = replacementChar; // Replace with the new character
        }
    }
}

int main() {
    char chArray[100]; // Declare a char array to hold the input string

    vector<char> ch;  // Declare a vector, though it's not used

    cout << "Enter your name:\n"; // Prompt user for input
    // cin >> ch; // This line is commented out; not needed since you're using getline
    // cin.getline(chArray, 100, '\n'); // This line is commented out; getline is used below
    cin.getline(chArray, 100); // Read a line of input from the user into 'chArray'

    int len = strlen(chArray); // Get the length of the input string

    // cinReplaceChar(chArray, ' ', '_',len);

    // Using std::replace instead of the custom cinReplaceChar function
    // This is a better approach because std::replace is a part of the STL,
    // making the code cleaner and more efficient.
    replace(chArray, chArray + len, ' ', '_'); // Replace spaces with underscores

    cout << "The new array is: " << chArray; // Print the modified string
   

    return 0; // Indicate that the program ended successfully
}
