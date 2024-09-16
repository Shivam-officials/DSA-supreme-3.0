#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to perform Binary Search between a given range [start, end]
int binarySearch(const vector<int> &v, int start, int end, int &target) {
  
  // Midpoint variable
  int mid;
  
  // Standard binary search loop that continues while start <= end
  while (start <= end) {
    mid = start + (end - start) / 2; // Calculate mid point to avoid overflow
    
    // If the target is found at mid, return its index
    if (v[mid] == target) {
      return mid;
    }
    // If the target is less than mid, search in the left half
    else if (v[mid] > target) {
      end = mid - 1;
    }
    // Otherwise, search in the right half
    else {
      start = mid + 1;
    }
  }
  
  // Return -1 if the target is not found
  return -1;
}

// Function to perform Exponential Search, optimized for large arrays when the element is near the beginning
int exponentialSearch(vector<int> v, int target) {
  int i = 0; // Starting index
  int n = v.size(); // Size of the array

  // Check if the first element is the target
  if (v[i] == target) {
    return i; // If found at the first element, return index 0
  }
  i++; // Move to the next element

  // Doubling the index while the value is less than or equal to the target and within bounds
  while (v[i] <= target && i < n) {
    i *= 2; // Double the index
  }

  // Perform Binary Search between i/2 and the minimum of i or n
  int ans = binarySearch(v, i / 2, min(i, n), target);
  cout << ans << endl;
  return ans;
}

// Function for Exponential Search in an unbounded array (useful for very large or infinite-sized arrays)
int exponentialSearchInUnboundedArray(vector<int> v, int target) {
  int i = 0; // Starting index
  int n = v.size(); // Size of the array

  // Check if the first element is the target
  if (v[i] == target) {
    return i; // If found at the first element, return index 0
  }
  i++; // Move to the next element

  // Doubling the index while the value is less than or equal to the target and within bounds
  while (v[i] <= target && i < n) {
    i *= 2; // Double the index
  }

  // Perform Binary Search between i/2 and i (since the array is unbounded, the end might not be n)
  int ans = binarySearch(v, i / 2, i, target);
  cout << ans << endl;
  return ans;
}

int main() {
  vector<int> v;

  // Fill the vector with sorted values (each element is twice the index)
  for (int i = 0; i < 100; i++) {
    v.push_back(i * 2); // Example: 0, 2, 4, 6, 8, ..., 198
  }

  int target = 450; // Target value to search

  // Call Exponential Search for a bounded array
  exponentialSearch(v, 40);

  // Call Exponential Search for an unbounded array
  exponentialSearchInUnboundedArray(v, 50);

  return 0;
}
