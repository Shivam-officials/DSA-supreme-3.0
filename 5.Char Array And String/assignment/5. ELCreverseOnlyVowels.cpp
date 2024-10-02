#include <cctype>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

bool isThisAVowel(char c) {
    
    c = tolower(c); // if char is bigger we will lower them otherwise we have to compare them to AEIOU too

    // Check if the character is a vowel (both lowercase and uppercase)
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
}

// TC = O(N) SC = O(1);
string reverseVowels(string s) {
    int low = 0, high = s.length() - 1;

    // Two-pointer approach to swap vowels
    while (low < high) {
        // Move low pointer until a vowel is found
        while (low < high && !isThisAVowel(s[low])) low++;
        
        // Move high pointer until a vowel is found
        while (low < high && !isThisAVowel(s[high])) high--;
        
        // Swap vowels found at low and high
        swap(s[low], s[high]);
        low++;
        high--;
    }
    return s;
}


int main(int argc, char const *argv[])
{
    cout << reverseVowels("IceCreAm");
    return 0;
}
