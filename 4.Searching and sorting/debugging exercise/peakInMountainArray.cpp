
#include <iostream>
#include <vector>
using namespace std;




int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low + high) >> 1;
            if(nums[mid] > nums[mid+1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
}
    
    int main()
{
     vector<int>v{7,8,9,8,7,6,5,3,1};
     cout << findPeakElement(v);
    return 0;
}