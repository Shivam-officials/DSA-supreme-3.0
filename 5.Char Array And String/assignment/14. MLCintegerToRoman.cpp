#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

/**
 ** @note if u have to compare something with number of values just store all those in a vector in decreasing order and compare them withh all just like the [intToRoman] function usefull in cases like now ki ye kisse bda hai 
 
 */

/*
Time Complexity: O(num), but since num is in the range [1, 3999], it's
effectively O(1). Space Complexity: O(1), as the output string length is bounded
by the max value of 3999.
*/
string intToRoman_ME(int num) {
  string ans = "";

  while (num > 0) {
    // If num is 1000 or more, add "M" and subtract 1000
    if (num >= 1000) {
      ans += "M";
      num -= 1000;
      // If num is 900-999, add "CM" (900) and subtract 900, else handle 500-899
      // with "D"
    } else if (num >= 500) {
      if (to_string(num)[0] == '9') {
        ans += "CM";
        num -= 900;
      } else {
        ans += "D";
        num -= 500;
      }
      // If num is 400-499, add "CD" (400), else handle 100-399 with "C"
    } else if (num >= 100) {
      if (to_string(num)[0] == '4') {
        ans += "CD";
        num -= 400;
      } else {
        ans += "C";
        num -= 100;
      }
      // If num is 90-99, add "XC" (90), else handle 50-89 with "L"
    } else if (num >= 50) {
      if (to_string(num)[0] == '9') {
        ans += "XC";
        num -= 90;
      } else {
        ans += "L";
        num -= 50;
      }
      // If num is 40-49, add "XL" (40), else handle 10-39 with "X"
    } else if (num >= 10) {
      if (to_string(num)[0] == '4') {
        ans += "XL";
        num -= 40;
      } else {
        ans += "X";
        num -= 10;
      }
      // If num is 9, add "IX", else handle 5-8 with "V"
    } else if (num >= 5) {
      if (to_string(num)[0] == '9') {
        ans += "IX";
        num -= 9;
      } else {
        ans += "V";
        num -= 5;
      }
      // If num is 4, add "IV", else handle 1-3 with "I"
    } else {
      if (to_string(num)[0] == '4') {
        ans += "IV";
        num -= 4;
      } else {
        ans += "I";
        num -= 1;
      }
    }
  }
  return ans;
}

//** FASTEST &  same code as my ME logic bt with better implementations 
string intToRoman(int num) {
    // Define pairs of integer values and their corresponding Roman numeral representations
    vector<pair<int, string>> values = {
        {1000, "M"}, 
        {900, "CM"}, 
        {500, "D"}, 
        {400, "CD"}, 
        {100, "C"}, 
        {90, "XC"}, 
        {50, "L"}, 
        {40, "XL"}, 
        {10, "X"}, 
        {9, "IX"}, 
        {5, "V"}, 
        {4, "IV"}, 
        {1, "I"}
    };

    string result;

    // Loop through the values array and construct the Roman numeral string
    for (const auto& romanMap : values) {
        while (num >= romanMap.first) {
            result += romanMap.second; // Append the Roman numeral to the result
            num -= romanMap.first;      // Subtract the value from num
        }
    }

    return result; // Return the constructed Roman numeral string
}

// Time Complexity: O(1)
// Space Complexity: O(1) 
string intToRoman_LeetCodeCopy(int num) {
    // Arrays for Roman numeral representations
    string thousands[4] = { "", "M", "MM", "MMM" };
    string hundreds[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    string tens[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    string ones[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

    // Error handling for out-of-bounds input
    if (num < 1 || num > 3999) {
        return ""; // or throw an exception
    }

    // Construct the Roman numeral string
    return thousands[num / 1000] + 
           hundreds[(num % 1000) / 100] + 
           tens[(num % 100) / 10] + 
           ones[num % 10];
}


int main() {
  cout << intToRoman_ME(3948)<<endl;
    cout << intToRoman_LeetCodeCopy(3948)<<endl;
    cout << intToRoman(3948)<<endl;
  return 0;
}
