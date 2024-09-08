#include <vector>
#include <iostream>
using namespace std;


// Given a sorted array arr[l of size N, some elements of array are arr(il may be moved to either of the adjacent positions, i.e.,
// present at or arr(i-l) i.e. arr(i) can only be swapped with either or arr[i-l). The task is to search for an element in this array.
// Input: arr() = {10, 3, 40, 20, 50, 80, 70}, key = 40 Output: 2
// Explanation: Output is index of 40 in given array i.e.2

int searchInNearlySortedArray(vector<int>nums,int target
){
     int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        int ans = -1;
        while(start<=end){
            mid = start + (end-start)/2;
            
            if(nums[mid] == target){
               return mid;
            }
            
            if(mid > 0 && nums[mid-1] == target){
                return mid-1;
            }
            
            if(mid < nums.size()-1 && nums[mid + 1] == target){
                return mid+1;
            }
            
            if(nums[mid]>target){
                end = mid-2;
            }else {
            start = mid+2;
            }
        
        }
        return ans;
}

int main(int argc, char const *argv[])
{
    vector<int>v{1, 2, 4, 3, 6, 5, 7, 9, 8, 10, 12, 11, 14, 13, 15, 17, 16, 18, 20, 19};
    cout << searchInNearlySortedArray(v, 6);
}
