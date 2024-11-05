#include <iostream>
#include <string>
using namespace std;


//TC = O(N)  SC = O(N)
int findLastCharLTR(string str,int index,char ch,int &ans){
    if(index == str.size())return -1;
    
    if(str[index]==ch)
        ans = index;

    findLastCharLTR(str, index+1, ch,ans); 
    return ans;
}

int findLastCharRTL(string str ,char ch, int index){
    if (index == -1) {
     return -1;
    }

    if (str[index]==ch) {
        return index;
    }
    return findLastCharRTL(str, ch, index-1);
}

int main(int argc, char const *argv[])
{
    string st = "aana aaja na";
    int ans = -1;
     cout<<findLastCharLTR(st,0,'n',ans)<<endl;
     cout << findLastCharRTL(st, 'j',st.length()-1);
    //  cout << ans;
    return 0;
}
