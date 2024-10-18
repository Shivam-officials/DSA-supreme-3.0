#include <iostream>
#include <vector>
using namespace std;


//TC = O(n) SC = O(n)
bool sortedOrNot_Myway(vector<int>array,int index){
    
    // Edge case: An empty array or a single-element array is always sorted
    if (array.size() <= 1) return true;

    // base case
    if(index == array.size()) return true;

    // processing ... ek case hum krenge
    if(array[index]<array[index - 1]) return false;

    // recursive call .... baki recursion dekh lega
   return sortedOrNot_Myway(array, index+1);
}



bool sortedOrNot_Sirway(vector<int>array,int index){

    //base case
    if(array.size() == index) return true ;
    bool currentAns  = false;
    bool recursionKaAns = false;

    // processing ..... 1 case mai krunga
    if(array[index]> array[index-1])
    {
        currentAns = true;
    }

    // recursive call .... baki case recursion kr dega
    recursionKaAns = sortedOrNot_Myway(array, index+1);

    // dono case true hai to array complete sorted
    return recursionKaAns && currentAns;
    
    
}

int main(int argc, char const *argv[])
{
    vector<int>arr {10,20,30,40,50};
    cout << sortedOrNot_Myway(arr,1)<<endl;
    cout << sortedOrNot_Sirway(arr, 1)<<endl;
    return 0;
}
