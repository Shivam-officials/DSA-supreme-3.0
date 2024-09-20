
#include <iostream>
#include <vector>
using namespace std;


int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while(l <= r){
			int mid = l + (r-l)/2;
			if(nums[mid] == target) return mid;
			else if(nums[l]<=nums[mid]){
				if(nums[l]<=target && target<nums[mid]) r = mid-1;
				else l = mid+1; 
			}
			else{
				if(nums[mid]<target && target<=nums[r]) l = mid+1;
				else r = mid-1;
			}
		}
		return -1; // No need to debug this line.
	}


// there will always be half or one side will sorted in the rotated array . so we can find which side is sorted by comparing the start and mid element then check if our target is in the sorted side or not if not it will be definately other side
int searchInrotatedArrayWithoutPivot(const vector<int> &v,int  &target){
    int start = 0;
    int end = v.size()-1;

    int mid = 0;
    while(start<=end)
    {
        mid  = start+(end-start)/2;

        if(v[mid] == target)
        {
            return mid;
        }

         if (v[start]<=v[mid]) { // if true left side is sorted so we can check if our target is this sorted side or not

            if(v[start]<=target && target <= v[mid])  
            {
                // element is in the sorted array side(left)
                end = mid-1;
            }else 
            {
                // it will in right
                start = mid+1;
            }
            
        
        }else // otherwise our right is sorted  and we will check here if our target is on this side or not
        {
            if (v[mid]<=target && target<=v[end]) {
                // element is in sorted array side (right)
                start = mid+1;
            }else 
            {
                // it will be in left side (unsorted side)
                end = mid - 1;
            }
        }
        
    }

    return -1;
    
}

    int main(int argc, char const *argv[])
    {
        
        vector<int>v{7,8,9,1,2,3,4,5,6,};
        int target =7;
        // cout<<searchInrotatedArrayWithoutPivot(v,target);
        cout<<search(v,target);
        return 0;
    }
    