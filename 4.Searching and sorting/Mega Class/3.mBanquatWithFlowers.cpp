
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

// Helper function to determine if it's possible to make `m` bouquets in `mid`
// days
bool isPossibleSolution(vector<int> &bloomDay, int m, int k, int mid) {
  unsigned long long flowerCount =
      0; // To keep track of adjacent flowers that have bloomed
  unsigned long long bouquetCount = 0; // To count the number of bouquets made

  // Traverse through each day's bloom status in the array
  for (int i = 0; i < bloomDay.size(); i++) {
    // If the flower blooms within or before the `mid` days
    if (bloomDay[i] <= mid) {
      flowerCount++; // Increment the flower count

      // If we've collected `k` adjacent flowers, make a bouquet
      if (flowerCount == k) {
        bouquetCount++;  // Increment the bouquet count
        flowerCount = 0; // Reset flower count for the next bouquet
      }
    } else {
      flowerCount = 0; // If the flower hasn't bloomed, reset the adjacent flower count
    }

    // If we've already made the required number of bouquets, return true ::early exit 
    if (bouquetCount >= m) {
      return true;
    }
  }

  // If unable to make the required number of bouquets, return false
  return false;
}

// Function to find the minimum number of days required to make `m` bouquets
int minDays(vector<int> &bloomDay, int m, int k) {
  int n = bloomDay.size();

  // Check if it's even possible to make `m` bouquets with `k` flowers each
  // If there aren't enough flowers, return -1
  if ((long long)m * k > n) {
    return -1;
  }

  // Binary search bounds: start with the minimum and maximum days in the
  // bloomDay array
  unsigned long long start = *min_element(bloomDay.begin(), bloomDay.end());
  unsigned long long end = *max_element(bloomDay.begin(), bloomDay.end());
  unsigned long long ans = -1;

  // Binary search to find the minimum number of days
  while (start <= end) {
    // Calculate the mid-point of the current range to avoid overflow
    unsigned long long mid = start + (end - start) / 2;

    // Check if it's possible to make `m` bouquets in `mid` days
    if (isPossibleSolution(bloomDay, m, k, mid)) {
      ans = mid;     // Store the result as a potential answer
      end = mid - 1; // Try to find a smaller number of days by adjusting the
                     // search space
    } else {
      start = mid +1; // Increase the number of days if not enough bouquets can be made
    }
  }

  // Return the minimum number of days found
  return ans;
}

int main() {
  vector<int> bloomDay{1,10,3,10,2};
    cout << minDays(bloomDay, 3, 1);
  return 0;
}