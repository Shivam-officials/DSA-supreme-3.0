#include<iostream>
#include <vector>
using namespace std;

//TC = O(logn) SC = O(n)
int binarySearch(vector<int> &array,int target,int start, int end ){

    int mid = (start + end )/2;

    // base case
    if(start>end) return -1;

    // processing ... 1 case maine solve kr dia 
    if(array[mid] == target){
        // ans = mid;
        return mid;
    } 
    
    // recursive calls ... baki case recursion solve kr dega
    if(array[mid]<target) return binarySearch(array, target, mid+1, end );
    else  return binarySearch(array, target, start, mid+1 );
    
}

int main(int argc, char const *argv[])
{
    vector<int>arr {1,2,3,4,5,6,7,8,9,10};

    cout<< binarySearch(arr, 100,0, arr.size()-1);
    
    return 0;
}
