#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void reverseCharArray(char ch[],int length){

    /*** @note simple "for loop method"       */

    // for(int i = 0; i < length/2; i++)
    // {
    //     swap(ch[i],ch[length-i-1]);
    // }

    // two pointer method
    int l = 0;
    int h = length-1;
    while(l<h)
    {
        swap(ch[l],ch[h]);
        l++;
        h--;
    }
    
    
}




int main()
{
    char ch[100];
    cout << "enter the string\n";
    cin.getline(ch,100);
    int len = strlen(ch);
    
    // reverse(ch, ch+len); // bydeault rever method

    reverseCharArray(ch,len);

    cout << ch;
    
    return 0;
}
