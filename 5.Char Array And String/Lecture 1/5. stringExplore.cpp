#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;






int main()
{
//    string str = "hey";

//    cout << "enter the char array \n";
//    getline(cin,str); // delimeter means it will not stop taking input untill it find that char 
//     // str.append(" yeah");
//     // str.push_back('z');

//     string str2 = "string 2";
//     str += " " + str2;
//     for(auto i = str.begin(); i < str.end(); i++)
//     {
//        cout<<*i << " ";
//     }
// or 
// cout << str<<endl;

//=========================================================

    string sentence = "it is my territery";
    cout<<endl;
    cout<<sentence.substr(4,5)<<endl;

    //===============================================================

    /**
     * @brief string find word or sentence in between
     */
    // auto pos = sentence.find("my");
    // if(pos != string::npos)  // here npos mean no position mean nowhere
    // {
    //    cout << "it is at "<<pos;
    // }else 
    // {
    //     cout << "it is not found";
    // }

    // ====================================================================
    
    /**
     * @brief string compare  if ans = 0 then equeal otherwise anyting else its not equal
     * 
     */
     string str2 = "say my name";
     cout << sentence.compare(str2);
    
    return 0;
}
