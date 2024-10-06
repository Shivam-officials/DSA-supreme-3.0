#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

// https://leetcode.com/problems/text-justification/description/

 /* 
   Intuition:
   - Use a `currentLine` vector to store words until adding another word exceeds `maxWidth`.
   - When the line exceeds `maxWidth`, distribute spaces between the words to fully justify the line.
   - **Edge case**: If `currentLine` has only one word, add all remaining spaces to the end.
   - Accumulate the words (with spaces) into a single string and push it into the result (`ans`).
   - Handle the last line by left-justifying it (spaces only at the end).
  */

void printElement(string a) { cout << a << "," << endl; }

/**
 * @warning Be cautious of using accumulate; it can increase time complexity due to repeated string copying.
 ** Use it only when the accumulated length is fixed and known, like in the specific case below.
 */



// TC = O(N)
// SC = O(N) 
/**
 * word iteration: O(N)
 * accumulation : O(L) Space for Current Line:
    The currentLine vector stores words for the current line being processed.
    Since the maximum number of words per line is limited by maxWidth, which is a constant relative to N, this is O(1) space. 
 */
vector<string> fullJustify_ME (vector<string> &words, int maxWidth) {
  vector<string> currentLine; // Temporary storage for words in the current line
  int totalNosOfChars = 0,
      totalNoOfSpaces = 0; // Track the total number of characters and spaces
  vector<string> ans;      // The final result to store all justified lines

  int i = 0; // Index for the words vector
  while (i < words.size()) {
    // Add words to the current line until the line reaches the maximum width
    while (i < words.size() && totalNoOfSpaces + totalNosOfChars + words[i].length() <= maxWidth) {
      currentLine.push_back(words[i]); // Add current word to the line
      totalNosOfChars += words[i].length(); // Update the total number of characters
      totalNoOfSpaces = currentLine.size(); // Update number of words in the current line
      i++;
    }

    // Calculate the remaining spaces to insert
    int spacesToAddLeft = maxWidth - totalNosOfChars;

    // Case 1: More than one word in the current line, distribute spaces evenly
    if (i < words.size() && currentLine.size() > 1) {
      int evenlySpacesToAdd = spacesToAddLeft / (currentLine.size() - 1); // Even space distribution
      int oddSpacesToAdd =  spacesToAddLeft %
          (currentLine.size() - 1); // Extra spaces for left justification

      // Insert evenly distributed spaces between words
      for (int j = 0; j < currentLine.size() - 1; j++) {
        string &currentWord = currentLine[j];
        for (int k = 0; k < evenlySpacesToAdd; k++) {
          currentWord += " "; // Add even spaces
        }
      }

      // Add any remaining spaces to the leftmost words
      int oddSpacesIndex = 0;
      while (oddSpacesToAdd--) {
        currentLine[oddSpacesIndex++] += " "; // Distribute remaining spaces
      }
    }

    // Case 2: Only one word in the current line, left-justify it
    else if (currentLine.size() == 1) {
      int leftSpacesToAdd =  maxWidth - totalNosOfChars; // Calculate remaining spaces
      while (leftSpacesToAdd--) {
        currentLine[0] += " "; // Add spaces to the right of the single word for
                               // left justification
      }
    }

    // Case 3: Last line , left-align the words
    else {
      int totalNoOfCharsInLastLine =
          0; // Initialize character count for the last line
      for (int j = 0; j < currentLine.size() - 1; j++) {
        currentLine[j] += " "; // Add one space between words
        totalNoOfCharsInLastLine += currentLine[j].length(); // Update character count
      }
      totalNoOfCharsInLastLine += currentLine.back().length(); // Include the last word's length

      int spacesLeftToAdd = maxWidth - totalNoOfCharsInLastLine; // Calculate remaining spaces
      while (spacesLeftToAdd--) {
        currentLine.back() += " "; // Add remaining spaces to the end of the
                                   // last word for left alignment
      }
    }

    // Construct the justified line and add it to the result
 
    string ansString = accumulate(currentLine.begin(),currentLine.end(),string());
    ans.push_back(ansString); // Store the final justified line
    

    // Reset for the next line
    currentLine.clear(); // Clear the temporary line storage
    totalNoOfSpaces = 0; // Reset space count
    totalNosOfChars = 0; // Reset character count
  }
  return ans; // Return the fully justified lines
}


 vector<string> fullJustify_Sir_Same_Logic_Better_Implementaion_And_Easy_Writing(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        vector<string> currentLine; //["this", "is", "an"]
        int currentLineTotalChars = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string &currentWord = words[i];
            int currentLineNeededNumberOfSpaces = currentLine.size(); // single space after word
            if (currentLineTotalChars + currentLineNeededNumberOfSpaces + currentWord.size() > maxWidth)
            // exceeding? means, currentLine without taking currentWord is complete.
            // fully justified case
            {
                int extraSpaces = maxWidth - currentLineTotalChars;
                int spacesGoInBetweenWords = extraSpaces / max(1, (int)(currentLine.size() - 1));
                int remainder = extraSpaces % max(1, (int)(currentLine.size() - 1));

                // We don't need spaces after last word
                for (int j = 0; j < currentLine.size() - 1; j++)
                {
                    // add even spaces
                    for (int k = 0; k < spacesGoInBetweenWords; k++)
                        currentLine[j] += " "; // add spaces after the word.

                    if (remainder > 0)
                    {
                        currentLine[j] += " ";
                        remainder--;
                    }
                }

                if (currentLine.size() == 1)
                {
                    // left justified case, because only 1 word in the line
                    while (extraSpaces--)
                        currentLine[0] += " ";
                }

                // let's prepare our final line
                string finalLine = "";
                for (string wordWithSpaces : currentLine)
                    finalLine += wordWithSpaces; // string concat

                ans.push_back(finalLine);
                currentLine.clear();
                currentLineTotalChars = 0;
            }

            // currentLine is not complete
            currentLine.push_back(currentWord);
            currentLineTotalChars += currentWord.size(); // not including spaces
        }

        // Let's take care of Last Line
        // add 1 space between words
        string finalLine = "";
        for (auto word : currentLine)
            finalLine += word + " ";

        finalLine.pop_back(); // removed extra added space

        // if still maxwidth is not acheived
        int leftSpaces = maxWidth - finalLine.size();
        while (leftSpaces--)
            finalLine += " ";
        ans.push_back(finalLine);
        return ans;
}

vector<string> fullJustify_sirCodeTestingMyself_MostPerfectAndOptimised (vector<string> &words, int maxWidth) {
  vector<string> ans, currentLine;
  int totalNumberOfCharsInCurrentline = 0;

  // Loop through each word in the input list
  for (auto currentWord : words) {
    int currentNeededNumberOfSpaces = currentLine.size();

    // Check if adding the current word would exceed the max width
    if (totalNumberOfCharsInCurrentline + currentNeededNumberOfSpaces + currentWord.length() > maxWidth) {
      int totalSpacesLeft = maxWidth - totalNumberOfCharsInCurrentline;
      int evenSpaces = totalSpacesLeft / max(1, (int)currentLine.size() - 1);
      int oddSpaces = totalSpacesLeft % max(1, (int)currentLine.size() - 1);

      // Distribute spaces between words for justification
      for (int i = 0; i < currentLine.size() - 1; i++) {
        string &currentLineWords = currentLine[i];
        currentLineWords += string(evenSpaces, ' ');  // Add even spaces

        // Add extra space if needed
        if (oddSpaces > 0) {
          currentLineWords += " ";
          oddSpaces--;
        }
      }

      // Handle single-word lines by adding all remaining spaces
      if (currentLine.size() == 1) {
        currentLine[0] += string(totalSpacesLeft, ' ');
      }

      // Combine the justified line and store it in the result
      ans.push_back(accumulate(currentLine.begin(), currentLine.end(), string()));

      // Reset for next line
      currentLine.clear();
      totalNumberOfCharsInCurrentline = 0;
    }

    // Add current word to the line and update char count
    currentLine.push_back(currentWord);
    totalNumberOfCharsInCurrentline += currentWord.length();
  }

  // Handle the last line (left-justified)
  for(auto &lastLineWord:currentLine) lastLineWord += " ";
  string leftJustifiedString = accumulate(currentLine.begin(), currentLine.end(), string());
  leftJustifiedString.pop_back(); // Remove the  space from the last word which added above in for range loop

  // Add remaining spaces to the end of the last line
  leftJustifiedString += string(maxWidth - leftJustifiedString.size(), ' ');
  ans.push_back(leftJustifiedString);

  return ans;
}




int main(int argc, char const *argv[]) {
  vector<string> words{"This",          "is", "an", "example", "of","text","justification."};
  // vector<string> words{"What", "must", "be", "acknowledgment", "shall", "be"};
  int maxWidh = 16;
  auto ans = fullJustify_Sir_Same_Logic_Better_Implementaion_And_Easy_Writing(words, maxWidh);
  auto ans2 = fullJustify_sirCodeTestingMyself_MostPerfectAndOptimised(words, maxWidh);

  for_each(ans.begin(), ans.end(), printElement);
  cout << endl<<endl;
  for_each(ans2.begin(), ans2.end(), printElement);

  cout << endl<<endl<<string(5,'a');
  
  return 0;
}
