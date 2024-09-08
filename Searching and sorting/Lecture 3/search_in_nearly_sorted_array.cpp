#include <vector>
#include <iostream>
using namespace std;

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
