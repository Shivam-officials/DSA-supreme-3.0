#include<iostream>
#include <vector>
using namespace std;


void evenPrint(vector<int>array,int index){
// base case
if(index == array.size()) return ;

// processing ..... ek case humne kia 
if((array[index]&1) == 0) cout<<array[index]<<" ";

// baki case recursive call kr deega
evenPrint(array, index+1);
}

int main(int argc, char const *argv[])
{
    vector<int>arr {1,2,3,4,5,6,7,8,9,10};
    evenPrint(arr,0);
    return 0;
}
