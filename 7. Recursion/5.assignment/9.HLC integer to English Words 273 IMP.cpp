#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;


// https://leetcode.com/problems/integer-to-english-words/description/


string processBatch_helperFn(int currBatch, int batchIndx) {
        const string thousandsAndBeyond[] = {"", "Thousand", "Million", "Billion"};
        const string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        string batchAns;
        if (currBatch >= 100) {
            int hunsIndx = currBatch / 100;
            batchAns += ones[hunsIndx] + " Hundred ";
            currBatch %= 100;
        }
        if (currBatch >= 20) {
            int tensIndx = currBatch / 10;
            batchAns += tens[tensIndx] + " ";
            currBatch %= 10;
        }
        if (currBatch > 0) {
            int onesIndx = currBatch;
            batchAns += ones[onesIndx] + " ";
        }
        batchAns += thousandsAndBeyond[batchIndx] + " ";
        return batchAns;
}


// TC = O(log10(num)) SC = O(log10(num)) // more easy to understand and faster due to non recursion approach
string numberToWordsIterative_LeetcodeCopy(int num) {
      if (num == 0) return "Zero";
      string ans;
      int batchIndx = 0;
      while (num > 0) {
          if (num % 1000 != 0) {
              string batchAns = processBatch_helperFn(num % 1000, batchIndx);
              ans = batchAns + ans;
          }
          num /= 1000;
          batchIndx++;
      }

       // Finds the last non-space character, then erases everything after it to remove trailing spaces from `ans`
      ans.erase(ans.find_last_not_of(" ") + 1); 
      
      return ans;
}


    
// best and intutive aaproach in recursion
// Recursive function to convert number to words based on mapping
// TC = O(log10(num)) SC = O(log10(num))
string numberToWords_bySir(int num, vector<pair<int, string>> &mp){
    if (num == 0) return "Zero"; // Special case for zero

    for (auto it : mp) {
      if (num >= it.first) {
        string a = "";
        if (num >= 100) a = numberToWords_bySir(num / it.first, mp) + " "; // Convert the left part of the number

        string b = it.second; // Get the current word representation from the map

        string c = "";
        if (num % it.first != 0) c = " " +  numberToWords_bySir(num % it.first, mp); // Convert the remaining part recursively

        return a + b + c; // Concatenate left part, current word, and remaining part
      }
    }
    return "";
}




int main(int argc, char const *argv[]) {
  int nm = 12345; // Input number to convert to words

  // Map of number parts to words, ordered from largest to smallest
  vector<pair<int, string>> mp{
      {1000000000, "Billion"},
      {1000000, "Million"},
      {1000, "Thousand"},
      {100, "Hundred"},
      {90, "Ninety"},
      {80, "Eighty"},
      {70, "Seventy"},
      {60, "Sixty"},
      {50, "Fifty"},
      {40, "Forty"},
      {30, "Thirty"},
      {20, "Twenty"},
      {19, "Nineteen"},
      {18, "Eighteen"},
      {17, "Seventeen"},
      {16, "Sixteen"},
      {15, "Fifteen"},
      {14, "Fourteen"},
      {13, "Thirteen"},
      {12, "Twelve"},
      {11, "Eleven"},
      {10, "Ten"},
      {9, "Nine"},
      {8, "Eight"},
      {7, "Seven"},
      {6, "Six"},
      {5, "Five"},
      {4, "Four"},
      {3, "Three"},
      {2, "Two"},
      {1, "One"},
  };

  // Convert the number to words and print it
  cout << numberToWords_bySir(nm, mp)<<endl;

  cout << numberToWordsIterative_LeetcodeCopy(nm);
  return 0;
}
