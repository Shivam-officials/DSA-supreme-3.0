#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// by defualt cpp funtion bt will not work bcz atoi() only takes int range value
int defualtAtoi(string s) { return atoi(s.c_str()); }

int makeNumber(string &s, int &sign) {
  if (s.length() > 10) {
    return sign == 1 ? INT_MAX : INT_MIN;
  }

  int num = 0;
  for (auto ch : s) {
    int digit = ch - '0'; // Convert char to digit
    // Check for overflow before adding the new digit
    if (num > (INT_MAX - digit) / 10) {
      return sign == 1 ? INT_MAX : INT_MIN;
    }
    num = num * 10 + digit;
  }

  return sign * num;
}

// works bt also works for "+-12" and give -12 ... which should not work and
// give 0
int myAtoi_Me(string s) {
  string number = "";
  int sign = 1;
  int low = -1;
  int high = s.length() - 1;
  for (int i = 0; i < s.length(); i++) {

    if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
        s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
        s[i] == '8' || s[i] == '9') {
      if (low == -1) {
        low = i;
      }
    } else if (low != -1) {

      high = i - 1;
      break;
      cout << "low is" << low << " high is " << high << endl;
    }
    if (s[i] >= 'a' && s[i] <= 'z') {
      break;
    }
  }
  if (low > 0 && s[low - 1] == '-') {
    sign = -1;
  }

  number = low != -1 && high != -1 ? s.substr(low, high - low + 1) : "0";
  // return sign * stoi(number);
  return makeNumber(number, sign);
}

int myAtoi_MeAgain(string s) {
  int number = 0;
  int sign = 1;
  bool numStarted = false; // Flag to check when to start processing digits

  for (auto ch : s) {
    // Skip leading spaces
    if (ch == ' ' && !numStarted) {
      continue;
    }

    // Handle sign if it's the first non-space character
    if (ch == '-' && !numStarted) {
      sign = -1;
      numStarted = true; // Mark that we've started processing
      continue;
    } else if (ch == '+' && !numStarted) {
      numStarted = true;
      continue;
    }

    // Stop if non-digit characters are found (including alphabets and '.')
    if (ch < '0' || ch > '9') {
      break;
    }

    // Convert char to digit
    int digit = ch - '0';

    // Overflow check before processing the next digit
    if (number > (INT_MAX - digit) / 10) {
      return sign == 1 ? INT_MAX : INT_MIN;
    }

    // Accumulate the digit into the number
    number = number * 10 + digit;
    numStarted = true; // Mark that we've started processing
  }

  return sign * number;
}

int myAtoi_SIR(string s) {
  int num = 0, i = 0, sign = 1; // Initialize variables: number, index, and sign
                                // (default +1 for positive)

  // Skip leading whitespace
  while (s[i] == ' ') {
    i++;
  }

  // Check for sign characters '+' or '-'
  if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }

  // Process each digit in the string
  while (i < s.size() && isdigit(s[i])) {  //note: isdigit() takes char and tell if its number or not

  // Convert char to digit bcz '0' has 48 ascii value and number 1,2 3... have 49,50,,51 etc so we can calculate numbers by difference 
    int digit = s[i] - '0'; 

    // Overflow check: Ensure that num * 10 + digit does not overflow
    if (num > (INT_MAX - digit) / 10) {
      return (sign == 1) ? INT_MAX : INT_MIN; // Return INT_MAX or INT_MIN depending on the sign
    }

    // Accumulate the digit into the number
    num = num * 10 + digit;
    i++;
  }

  // Return the final number multiplied by its sign
  return num * sign;
}

int main() {
  //   cout << myAtoi("-___-");
  string ch = "       -91283472332";

  cout << myAtoi_SIR(ch) <<endl;

  // both default function bt they dont handle overflow cases
  cout << stoi(ch)<<endl;       // Converts C++ string to integer
  cout << atoi(ch.c_str())<<endl;  //atoi()-> Converts C-string to integer  // c_str()->  Converts cpp string to C-style string
  return 0;
}
