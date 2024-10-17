#include <climits>
#include <iostream>
using namespace std;


int maxInArrayRecursive(int * array,int size,int index,int ans){
    
    // base condition
    if(index == size)return ans;
    // processing ... 1 case hmne solve kia 
    if(array[index] > ans) ans = array[index];

    // recursive call ... baki k case recursion dekh lega
    ans = maxInArrayRecursive(array, size, index+1, ans);
    
    return ans;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50};

    cout << maxInArrayRecursive(arr,5,0,INT_MIN);
    return 0;
}
