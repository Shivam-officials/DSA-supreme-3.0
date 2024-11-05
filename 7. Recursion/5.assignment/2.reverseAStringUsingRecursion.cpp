#include <iostream>
using namespace std;


//TC = O(N)  SC = O(N)
void reverseStringThrougRecursion(string &str,int l, int r){
// base case
if(l >=r) return;
// processsing .. 1 case hum krenge
swap(str[l],str[r]);

// baki case recursio sambhal lega ........recursion relation
reverseStringThrougRecursion(str, l+1, r-1);
}


int main(int argc, char const *argv[])
{
    string str = "shivam";
    reverseStringThrougRecursion(str,0,5);
    cout << str;
    return 0;
}
