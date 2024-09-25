// https://leetcode.com/problems/find-and-replace-pattern/description/

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;


// we normallis the characters into abc...... form bcz only then we can compare them if they follow the pattern or not otherwise mapping will be very hard to map the words with pattern bcz we will not be able to verify if the char in the words is mapped with pattern 's some char before or not .. so we normallise both of them and then compare if same then pattern matched otherwise not

void normalise(string &word){
    char start = 'a';
    unordered_map<char, char> mapping;

    // Map each unique character in the word to the next available letter starting from 'a'
    for (auto ch : word) {
        if (mapping.find(ch) == mapping.end()) {
            mapping[ch] = start++;
        }
    }

    // Replace characters in the word based on the mapping
    for (auto &ch : word) {
        ch = mapping[ch];
    }
    
}


// TC = O(n * m) where n = words array length, m = word/pattern length
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    
    vector<string> ans;

    // Normalize the pattern for comparison
    normalise(pattern);

    // Iterate over each word, normalize it, and compare with the normalized pattern
    for (auto str : words) {
        string currentWord = str; // Save the original word
        normalise(str); // Normalize the word for pattern comparison

        // If the normalized word matches the normalized pattern, add the original word to the result
        if (str == pattern) {
            ans.push_back(currentWord);
        }
    }
    
    return ans;
}


void printElement(string a){
    cout << a << endl;
}

int main()
{
   vector<string> wordArray{"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    
   auto matchedPattern =  findAndReplacePattern(wordArray, pattern);

    for_each(matchedPattern.begin(), matchedPattern.end(), printElement);
     
    return 0;
}
