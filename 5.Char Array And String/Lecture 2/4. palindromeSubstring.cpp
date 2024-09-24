// https://leetcode.com/problems/palindromic-substrings/

#include <iostream>
#include <vector>
using namespace std;



/**
 * @note INTUITION:
 * If you expand a window around a character, considering it as the center, 
 * and continue expanding equally on both sides while the characters match, 
 * you will find all possible palindromic substrings that can be formed with 
 * that center. This works for both odd and even-length palindromes.
 * 
 * For odd-length palindromes, use the same character as the center (center, center),
 * and for even-length palindromes, use two consecutive characters as the center 
 * (center, center+1).
 */


int palindromeSubstring(string str , int low , int high){
    int count = 0;
    
    // Expand around the center while the characters at 'low' and 'high' are equal,
    // indicating a palindrome. Stop expanding if the characters mismatch.
    while(low >= 0 && high < str.length() && str[low] == str[high])
    {
        count++;    // Count this palindrome substring
        low--;      // Move left pointer inward
        high++;     // Move right pointer inward
    }
    return count;
}

int palindromeSubstringCount(string s){
    int ans = 0;

    // Traverse through each character as the potential center of palindromes to find out how many palindrome substring can be around it 
    for(int center = 0; center < s.length(); center++)
    {
        // Count palindromic substrings with odd lengths, expanding around 'center'
        int oddSizePalindromeSubstring = palindromeSubstring(s, center, center);

        // Count palindromic substrings with even lengths, expanding between 'center' and 'center + 1'
        int evenSizePalindromeSubstring = palindromeSubstring(s, center, center + 1);

        // Sum up all found palindromic substrings
        ans += oddSizePalindromeSubstring + evenSizePalindromeSubstring;
    }
    return ans;
}




int main()
{
   string str = "aaa";

   cout<< palindromeSubstringCount(str);

    
    return 0;
}
