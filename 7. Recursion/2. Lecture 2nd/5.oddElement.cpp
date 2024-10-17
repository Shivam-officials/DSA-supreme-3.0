#include<iostream>
#include <vector>
using namespace std;


void oddPrint(vector<int>array,int index){
// base case
if(index == array.size()) return ;

// processing ..... ek case humne kia 
if(array[index]&1) cout<<array[index]<<" ";

// baki case recursive call kr deega
oddPrint(array, index+1);
}

int main(int argc, char const *argv[])
{
    vector<int>arr {1,2,3,4,5,6,7,8,9,10};
    oddPrint(arr,0);
    return 0;
}
