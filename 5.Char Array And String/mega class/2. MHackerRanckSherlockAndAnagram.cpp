#include <algorithm>
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem

int sherlockAndAnagrams(string s) {
    int pairs = 0;
    unordered_map<string, int> mp;
    for(int i = 0; i<s.length(); i++){
        for(int j = i; j<s.length();j++){
            string str = s.substr(i,j-i+1);
            sort(str.begin(),str.end());
            mp[str]++;
        }
    }
    
    for(auto it:mp){
        int count = it.second;
        pairs += count*(count - 1)/2;
    }
    return pairs;
}

int main(int argc, char const *argv[])
{
    cout << sherlockAndAnagrams("cdcd");
    return 0;
}
