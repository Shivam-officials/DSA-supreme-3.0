#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

//TC = O(n) SC = O(n)
int maxInArrayRecursive(int * array,int size,int index,int ans){
    
    // base condition
    if(index == size)return ans;
    // processing ... 1 case hmne solve kia 
    if(array[index] > ans) ans = array[index];

    // recursive call ... baki k case recursion dekh lega
    ans = maxInArrayRecursive(array, size, index+1, ans);
    
    return ans;
}

//another less preferred way when it returns bt it a little bit roundabout way 
int maxAns(vector<int>array,int index){
    if(index == array.size())return 0;

    int ans = INT_MIN;
    ans = max(ans,array[index]);
    int recurAns=maxAns(array, index+1);
    return max(ans,recurAns);
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,33,30,2240,50};
    vector<int> arr2 = {10,20,30,33,2240,50};

    cout << maxInArrayRecursive(arr,5,0,INT_MIN)<<endl;
    cout << maxAns(arr2, 0);
    return 0;
}
