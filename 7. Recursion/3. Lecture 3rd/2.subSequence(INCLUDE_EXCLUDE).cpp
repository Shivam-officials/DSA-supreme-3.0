#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

// TC = O(2^N) SC = O(N)
void findAllSubsequenceWithBits(string input) {
  int count = pow(2, input.size()); // Total subsequences (2^n)
  for (int i = 0; i < count; i++) { // Iterate from 1 to exclude the empty subsequence
    int index = input.size() - 1;  // Start from the last character
    string ans = "";               // Store the current subsequence
    for (int j = i; j != 0; j >>= 1, index--) { // Process bits of i
      if (j & 1) ans.push_back(input[index]);  // Add character if bit is set
    }
    reverse(ans.begin(), ans.end());          // Reverse to correct order
    cout << ans << endl;                      // Print subsequence
  }
}

// TC = O(2^N) SC = O(N)
void findAllSubsequence(string inputString, string outputString, int index,  vector<string> &ans) {

  // base case ... rukna kab hai
  if (index == inputString.length()) {
    // cout << outputString << endl;
    ans.push_back(outputString);
    return;
  }

  // processing and recursion togethor
  // include krdo
  findAllSubsequence(inputString, outputString + inputString[index], index + 1, ans);

  // exclude krdo
  findAllSubsequence(inputString, outputString, index + 1, ans);
}

int main(int argc, char const *argv[]) {
  string input = "abc", output = "";

  vector<string> ans;

  findAllSubsequence(input, output, 0,ans);

  for (auto ch : ans) {
    cout << ch<<endl;
  }

  cout << "-------------------" << endl;
  findAllSubsequenceWithBits("abc");
  return 0;
}
