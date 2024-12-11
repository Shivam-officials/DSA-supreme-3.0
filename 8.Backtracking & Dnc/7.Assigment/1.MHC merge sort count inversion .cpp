#include <iostream>
#include <vector>
using namespace std;

// https://www.hackerrank.com/challenges/ctci-merge-sort/problem

// Merge function: Using Bubble Sort logic (inefficient for counting
// inversions). Time Complexity: O(N^2), Space Complexity: O(1).
void mergeIt(vector<int> &v, int start, int mid, int end, long &count) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = start + 1; i <= end; i++) {
      if (v[i] < v[i - 1]) {
        swap(v[i], v[i - 1]);
        swapped = true;
        count++;
      }
    }
  }
}

// Merge function: Efficiently merges two sorted halves while counting
// inversions. Time Complexity: O(N), Space Complexity: O(N).
// kind of uses the inplace mergesort shifting values till it reaches its right point type approach in a different way
void mergeIt2_With_Help_Of_Sir(vector<int> &v, int start, int mid, int end, long &count) {
  vector<int> left{v.begin() + start, v.begin() + mid + 1};
  vector<int> right{v.begin() + mid + 1, v.begin() + end + 1};

  int i = 0, j = 0, k = start;
  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      v[k++] = left[i++];
    } else {
      v[k++] = right[j++];
      count += left.size() - i; // Count inversions.
    }
  }
  while (i < left.size())
    v[k++] = left[i++];
  while (j < right.size())
    v[k++] = right[j++];
}

// Merge Sort function: Recursively sorts and merges subarrays, counting
// inversions. TC: O(N log N), SC: O(N) for mergeIt2.
void mergeSort(vector<int> &v, int start, int end, long &count) {
  if (start == end)
    return; // Base case: Single element is already sorted.
  int mid = (start + end) / 2;
  mergeSort(v, start, mid, count);                      // Sort left half.
  mergeSort(v, mid + 1, end, count);                    // Sort right half.
  mergeIt2_With_Help_Of_Sir(v, start, mid, end, count); // Merge halves.
}

// Wrapper function to count inversions using Merge Sort.
long countInversions(vector<int> v) {
  long count = 0;
  mergeSort(v, 0, v.size() - 1, count);
  return count;
}

//==============  SIR WAY ==================== 

// Brute Force approach: Compare each pair and count inversions.
// note: INTUTION :: Count inversions: For each element, count how many elements
// to its right are smaller (i.e., v[i] > v[j] for i < j).
// Approach: Nested loops to compare all pairs. Time Complexity: O(n^2), Space Complexity: O(1).
int countInversion_Simple_BY_Sir(vector<int> v) {
  int count = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] > v[j])
        count++;
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  vector<int> v{7, 9, 5, 6, 2};
  cout << countInversions(v) << endl;      // Efficient method.
  cout << countInversion_Simple_BY_Sir(v); // Brute force method.
  return 0;
}

