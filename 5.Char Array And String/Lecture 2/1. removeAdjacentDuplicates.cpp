// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <iostream>
#include <vector>
using namespace std;

//  TC = o(n^2) 
//  erase function is a heavy on time complexity function so we should avoid using it
string removeDuplicates_BruteForce(string s) {

  int i = 1;
  while (i < s.length()) {
    if (i >= 1 && s.at(i) == s.at(i - 1)) {
      s.erase(i - 1, 2); // Erase the adjacent characters
      i--;                 // Move back one step
    } else {
      i++; // Move forward
    }
  }

  return s;
}

// TC o(n) SC = o(n)
string removeDuplicates_optimized(string s) {
    string str = "";  
    for(auto c: s) {
        if (str.empty()) {
            str.push_back(c);  // Push the first character
        } else if (c == str.back()) {
            str.pop_back();  // Remove the last character if it matches the current one
        } else {
            str.push_back(c);  // Otherwise, push the current character
        }
    } 
    return str;
}


int main() {
  string s = "abbaca";

  //    cout << "enter the char array \n";
  //    cin>> s;

  // cout << removeDuplicates_BruteForce(s);

  cout << removeDuplicates_optimized(s)<<endl;

  return 0;
}
