#include <iostream>
using namespace std;

//ques
void shiftQuest(char input[]){
    int i =1;
    for(i=1;input[i]!='\0';i++)
        input[i-1] = input[i];
    input[i-1] = '\0';
}
void removeXQuest(char input[]) {
    if(input[0]=='x'){
        shiftQuest(input);
    	removeXQuest(input);
    }
    else
    removeXQuest(input+1);
}

/*
Example:
xxab --> ab
*/


// ans
void shift(char input[]){
    int i =1;
    for(i=1;input[i]!='\0';i++)
        input[i-1] = input[i];
    input[i-1] = '\0';
}
void removeX(char input[]) {
    if(input[0]=='\0') return ; // base condition it was missing in ques
    if(input[0]=='x'){
        shift(input);
    	removeX(input);
    }
    else
    removeX(input+1);
}

/*
Example:
xxab --> ab
*/

int main(int argc, char const *argv[])
{
    char ch[] =  "xxab";
    removeX(ch);
    cout << ch;
    return 0;
}
