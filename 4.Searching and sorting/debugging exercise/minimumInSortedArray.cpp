#include <iostream>
#include <vector>
using namespace std;


// assumes that the array is rotated always and where are we  comparing mid with start and end 
int findMin2(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, ans = start;
        while(nums[start] > nums[end]) { 
            int mid = (start + end) >> 1;
            if(nums[mid] <= nums[start] && nums[mid] <= nums[end]) 
                end = mid;
            else if(nums[mid] >= nums[start] && nums[mid] >= nums[end])
                start = mid + 1;          
            else return nums[mid];
            ans = start;
        }
        return nums[ans];
    }


// intituion - if its mid value is less than end value it is in the sorted array side and minimum value will be other side including mid
int findMinimumInSortedArray(vector<int>& v){

    int start = 0;
    int end = v.size()-1;
    int mid;

    

    while(start<end)
    {   
        mid = start + (end - start) / 2;
        if ( v[mid]<v[end] ) {
            end = mid;
        }else 
        {
            start = mid+1;
        }
    }

    return v[start];
    
}


int main()
{
    vector<int>v{7,8,9,1,2,3,4,5,6};
    cout << findMin2(v);
    return 0;
}
