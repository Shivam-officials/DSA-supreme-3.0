// https://leetcode.com/problems/custom-sort-string/description/


#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


string customSortString(string order, string s) {
    // Sort string 's' based on the custom order defined in 'order'
    sort(s.begin(), s.end(), [order](char a, char b) {
        // Compare positions of 'a' and 'b' in 'order' and sort accordingly
        return order.find(a) < order.find(b);
    });

    // Return the sorted string
    return s;
}



int main()
{
   string order = "bcafg";
   string str = "abcd";

   cout << customSortString(order, str);
   

    
    return 0;
}


