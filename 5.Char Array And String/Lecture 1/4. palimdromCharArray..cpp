#include <iostream>
#include <sec_api/string_s.h>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

bool isPalidrome(char ch[],int length){
    int low = 0;
    int high = length-1;
    while(low<high)
    {
        if(ch[low]!=ch[high])
        {
            return false;
        }
        low++;
        high--;
        
    }
    return true;
}


/**
 * @note palimdrome example
 *  racecar, wow , mom , dad, madam,lol, etc
 */

int main()
{
   char ch[100];

   cout << "enter the char array \n";
   cin.getline(ch,100);

    int len = strlen(ch);
     if(isPalidrome(ch,len)){
        cout<<"it is palimdrome \n";
     }else 
     {
        cout << "it is not palimdrome \n";
     }
    

    return 0;
}
