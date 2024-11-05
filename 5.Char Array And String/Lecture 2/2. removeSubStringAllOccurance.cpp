// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// TC =  O(str.length() * part.length()) bcz of find function 
string remove_all_occurrences_of_a_substring_BRUTEFORCE_ME(string str,string part){
   while(str.find(part) != string::npos) // tc = O( str.length()/part.length() )
   {
    int index = str.find(part);
    str.erase(index,part.length());
   }
   
    return str;
}


int main()
{
   cout << remove_all_occurrences_of_a_substring_BRUTEFORCE_ME("axxxxyyyyb","xy");
    
    return 0;
}
