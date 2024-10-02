#include <iostream>
using namespace std;

// https://leetcode.com/problems/reverse-only-letters/description/

bool isThisALetter(char ch) {
    // Checks if the character is an alphabet (both uppercase and lowercase)
    return (ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A');
}


// Time Complexity: O(n), where n is the length of the string (each character is processed once)
// Space Complexity: O(1), as we are modifying the string in-place
string reverseOnlyLetters(string s) {
    int low = 0, high = s.length() - 1;
    
    // Two-pointer approach to swap only letters
    while (low < high) {
        // Skip non-letter characters from the left
        while (!isThisALetter(s[low]) && low < high) low++;
        // Skip non-letter characters from the right
        while (!isThisALetter(s[high]) && low < high) high--;
        
        // Swap valid letters at 'low' and 'high'
        swap(s[low], s[high]);
        low++;
        high--;
    }
    
    return s;
}

// both are same its just this one is more readable and other one is more logical TC = O(N) Sc = O(1)
string reverseOnlyLetters2(string s) {
    int low = 0, high = s.length() - 1;
    
    // Two-pointer approach to reverse only letters
    while (low < high) {
        if (isThisALetter(s[low]) && isThisALetter(s[high])) {
            // Swap when both low and high point to letters
            swap(s[low], s[high]);
            low++;
            high--;
        } else if (!isThisALetter(s[low])) {
            // Move low pointer forward if it's not a letter
            low++;
        } else {
            // Move high pointer backward if it's not a letter
            high--;
        }
    }
    
    return s;
} 
int main(int argc, char const *argv[])
{
    string str ="ab-cd";
    cout << reverseOnlyLetters(str);
    return 0;
}
