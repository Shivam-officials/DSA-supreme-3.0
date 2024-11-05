#include <iostream>
using namespace std;

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// TC = O(N^2) SC = O(N/M) n length of string , m length of part
void removeOccurrencesRe(string & str,string & part){
    int found = str.find(part); // find TC -> O(N*M)

    // base case
    if(found ==string::npos) return ;
    
    // 1 case hum krenge 
    // str.erase(found,part.length());
    string st_left = str.substr(0,found); // 0(M) m is length of substring
    string st_right = str.substr(found+part.length());
    str = st_left+st_right;

    //baki recursion sambhal lega
    removeOccurrencesRe(str, part);
}

int main(int argc, char const *argv[])
{
    string st = "daabcbaabcbc",part = "abc";
    removeOccurrencesRe(st, part);
    cout << st;
    return 0;
}
