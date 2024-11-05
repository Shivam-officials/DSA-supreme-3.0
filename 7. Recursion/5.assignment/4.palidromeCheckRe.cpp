#include <iostream>
using namespace std;

//TC = O(N)  SC = O(N)
bool isPalindromeRe1(string str,int l, int r){
    // base case 
    if(l>=r)return true;


    // processing ... 1 maine chek kr lia 
    if(str[l]!=str[r]) return false;

    // recursive relation ... baki recursion check kr lega
    return isPalindromeRe1(str, ++l, --r);

}


bool isPalindromeRe2(string str,int l, int r){
    // base case 
    if(l>=r)return true;

    bool ans1 ;
    // processing
    if(str[l]==str[r]) ans1 = true;

    // recursive relation
    bool ans2=  isPalindromeRe2(str, ++l, --r);
    return ans1 && ans2 ;
}

int main(int argc, char const *argv[])
{
    string str = "racecar";
    cout << isPalindromeRe2(str,0,str.length()-1);
    return 0;
}
