#include <iostream>
#include <vector>
using namespace std;


// this will work
int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = int(nums.size()-1);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 and nums[left - 1] == target) { // it will work bcz even if we are adding modifiyig the left to mid+1 even when the ans is found 
            return left - 1;
        } else {
            return -1;
        }
}

int main(int argc, char const *argv[])
{
    vector<int>v{1,2,3,4,5,6,7,8,9,10,11};
    cout << binarySearch(v, 2);
    return 0;
}
