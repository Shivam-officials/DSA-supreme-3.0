#include <algorithm>
#include <cmath>
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
vector<int> kClosestElementsTwoPointerShrinkingWindow(vector<int> nums, int k,int x) {

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

// NOTE - in the windw expanding approach always make sure u r exluding the
// values low and high it will make sure that window contains only required
// values and also helps to handle many edge cases by defualt like edge cases
// when the array size is one or two
vector<int> kClosestElementsTwoPointerExpandingWindow(vector<int> nums, int k, int x) {

  // Find the index of the first element that is not less than x using
  // lower_bound
  auto highIt = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
  int n = nums.size();

  // Set high to the found index, or the last element if x is greater than all
  // elements
  int high = highIt > n - 1 ? n - 1 : highIt;
  if (high == 0) {
    high++;
  }

  // Set low to one element before high
  int low = high - 1;

  // Expand the window from the middle until the window contains exactly k
  // elements exluding the the elements on low and high
  // while (k--)
  while (high - low - 1 < k) {
    if (low < 0) {
      high++; // If low is out of bounds, increase high
    } else if (high == n) {
      low--; // If high is out of bounds, decrease low
    } else if (x - nums[low] <= nums[high] - x) {
      low--; // If the left element is closer, move left
    } else {
      high++; // Otherwise, move right
    }
  }

  // Return the subarray between low and high (inclusive) containing k closest
  // elements
  return vector<int>(nums.begin() + low + 1, nums.begin() + high);
}

// sort with custom comparator ans return the first k elements
vector<int> kClosestElementWithCustomComparatorSorting(vector<int> v, int k,int x) {
  // Step 1: Sort the vector 'v' based on closeness to 'x'
  std::sort(v.begin(), v.end(), [&x](int a, int b) {
    // Custom comparator: Compare based on absolute difference from 'x'
    return abs(a - x) < abs(b - x);
  });

  // Step 2: Create a new vector to store the 'k' closest elements
  std::vector<int> ans;
  for (int i = 0; i < k; i++) {
    // Add the first 'k' elements (closest to 'x') to the answer vector
    ans.push_back(v[i]);
  }

  // Step 3: Sort the 'k' closest elements in ascending order
  std::sort(ans.begin(), ans.end());

  // Step 4: Print each element using the printElement function
  std::for_each(ans.begin(), ans.end(), printElement);

  // Return the vector containing the 'k' closest elements
  return ans;
}

int main() {

  vector<int> v{1, 2};
  int x = 3;

  // for_each(v.begin(), v.end(), printElement);
  // auto ans = kClosestElementsTwoPointerShrinkingWindow(v, 5, 11);
  // auto ans = kClosestElementsTwoPointerExpandingWindow(v, 4, 3);
  kClosestElementWithCustomComparatorSorting(v, 1, 1);
  return 0;
}
