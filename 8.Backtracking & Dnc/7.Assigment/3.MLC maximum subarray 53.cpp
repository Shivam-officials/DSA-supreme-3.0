#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/

// TC = O(n log n), SC = O(1)
 // Function to find the maximum subarray sum using Divide and Conquer
int maximumSubArraySumDnC(vector<int> &nums, int start, int end) {
  // Base case: if the subarray has one element
  if (start == end) return nums[start];

  // Calculate the midpoint of the current subarray
  int mid = (start + end) / 2;

  // Recursively find the maximum subarray sum in the left and right halves
  int maxLeftSum = maximumSubArraySumDnC(nums, start, mid);
  int maxRightSum = maximumSubArraySumDnC(nums, mid + 1, end);

  // Find the maximum subarray sum crossing the midpoint
  int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
  int leftBorderSum = 0, rightBorderSum = 0;

  // Calculate maximum sum including elements from the left half crossing the midpoint
  for (int i = mid; i >= start; i--) {
    leftBorderSum += nums[i];
    if (leftBorderSum > maxLeftBorderSum) { maxLeftBorderSum = leftBorderSum; }
  }

  // Calculate maximum sum including elements from the right half crossing the midpoint
  for (int i = mid + 1; i <= end; i++) {
    rightBorderSum += nums[i];
    if (rightBorderSum > maxRightBorderSum) { maxRightBorderSum = rightBorderSum;}
  }

  // Combine the maximum left, right, and cross-border sums
  int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

  // Return the maximum of the three sums
  return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}


int maxSubArray(vector<int> &nums) {
  return maximumSubArraySumDnC(nums, 0, nums.size() - 1);
}

int main(int argc, char const *argv[]) {
  vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << maxSubArray(v);
  return 0;
}
