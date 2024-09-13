#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;


// LC 658  https://leetcode.com/problems/find-k-closest-elements/description/

void printElement(int a) { cout << a << endl; }

// INTUTION: [SHRINKING WINDOW] the intution here is to find the window which
// contains the k closest elements
//  of x and for tht we take the whole array as window and shrink that window
//  based on who is farthest untill the window is only contain the k elements
//  TC o(n-k) SC o(1)
vector<int> kClosestElementsTwoPointerShrinkingWindow(vector<int> nums, int k, int x) {

  // Initialize two pointers: low at the beginning, high at the end of the array
  int low = 0;
  int high = nums.size() - 1;

  // Narrow the window (high - low) until its size is equal to k
  while (high - low >= k) {
    // If the element at the low end is farther from x than the element at the
    // high end, move the low pointer inward (i.e., discard the element at low)
    if (x - nums[low] > nums[high] - x) {
      low++;
    } else {
      // Otherwise, move the high pointer inward (i.e., discard the element at
      // high)
      high--;
    }
  }

  // Once the window size is reduced to exactly k, return the subarray between
  // low and high (inclusive)
  return vector<int>(nums.begin() + low, nums.begin() + high + 1);
}


// NOTE - in the windw expanding approach always make sure u r exluding the values low and high
// it will make sure that window contains only required values and also helps to handle many edge cases
// by defualt like edge cases when the array size is one or two
vector<int> kClosestElementsTwoPointerExpandingWindow(vector<int> nums, int k,int x){
 
           	// Find the index of the first element that is not less than x using lower_bound
            auto highIt = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int n = nums.size();

           	// Set high to the found index, or the last element if x is greater than all elements
            int high = highIt > n - 1 ? n - 1 : highIt;
            if (high == 0 )
            {
                high++;
            }

           	// Set low to one element before high
            int low = high - 1;

           	// Expand the window from the middle until the window contains exactly k elements exluding the the elements on low and high
            // while (k--)
            while (high - low -1 < k)
            {
                if (low < 0)
                {
                    high++;	// If low is out of bounds, increase high
                }
                else if (high == n)
                {
                    low--;	// If high is out of bounds, decrease low
                }
                else if (x - nums[low] <= nums[high] - x)
                {
                    low--;	// If the left element is closer, move left
                }
                else
                {
                    high++;	// Otherwise, move right
                }
            }

           	// Return the subarray between low and high (inclusive) containing k closest elements
            return vector<int> (nums.begin() + low + 1, nums.begin() + high);
}

int main() {

  vector<int> v{1, 2, 3, 4, 5};
  // vector<int> v{2,4,6,8,10,12,14,16,18,20,24,26,28};
  // auto lowerBoundIndex = lower_bound(v.begin(),v.end(),4) ;
  // int lowerIndex = lower_bound(v.begin(),lowerBoundIndex,5) -v.begin();
  // auto it = upper_bound(v.begin(),v.end(),4);
  // cout << lowerIndex;
  int x = 9;

  // auto ans = kClosestElementsTwoPointerShrinkingWindow(v, 5, 11);
  auto ans = kClosestElementsTwoPointerExpandingWindow(v, 4, 3);
  for_each(ans.begin(), ans.end(), printElement);
  return 0;
}
