#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Function to merge two sorted arrays (v1 and v2) without using extra space
//idea: BEST method for large array with lowest time complexity
// TC = O((n+m)⋅log(n+m)) outer loop = O(log(m+n)) inner loop = O(m+n) 
//Sc = O(1);
void mergeTwoSortedOne_gap_method(vector<int> &v1, vector<int> &v2) {
  int totalSize = v1.size() + v2.size();       // Total size of combined arrays
  int gap = (totalSize / 2) + (totalSize % 2); // Initial gap for comparison
  int n = v1.size(), m = v2.size();            // Sizes of individual arrays

  // Gap method to sort the arrays
  while (gap > 0) {
    int i = 0, j = gap; // Pointers for comparison
    while (j < totalSize) {
      // Both elements are in v1
      if (i < n && j < n && v1[i] > v1[j]) {
        swap(v1[i], v1[j]);
      }
      // One element in v1 and the other in v2
      else if (i < n && j >= n && v1[i] > v2[j - n]) {
        swap(v1[i], v2[j - n]);
      }
      // Both elements are in v2
      else if (i >= n && j >= n && v2[i - n] > v2[j - n]) {
        swap(v2[i - n], v2[j - n]);
      }
      i++;
      j++;
    }
    gap = (gap > 1) ? (gap / 2) + (gap % 2) : 0; // Reduce the gap
  }
}



// helper function
void quickPartitionShift(vector<int> &v2) {
  int i = 0;
  while (i < v2.size() - 1 && v2[i] > v2[i + 1]) {
      
    //idea:swap
    // swap(v2[i], v2[i + 1]); // little overhead bt concise
    
    // no extra varible bt also not so fast
    // v2[i] = v2[i] ^ v2[i+1];
    // v2[i+1] = v2[i+1] ^ v2[i];
    // v2[i] = v2[i] ^ v2[i+1];
    
    // best and fastest ... passs all the test cases 
    int temp = v2[i];
    v2[i] = v2[i+1];
    v2[i+1] = temp;
    
    
    i++;
  }
}

// Intuition: Start from v1[0], compare each element with v2[0] (smallest in v2).
// If a value in v1 is greater than v2[0], swap it with v2[0]. After swapping,
// ensure v2[0] is moved to its correct position in v2 using insertion logic.

/** intution explained
    // note:INtution tum v1 me zero(i) se aage bdo aur her index pe usko v2 ki sbse
    // choti value jo ki v2[0] pe hi hogi usse compare kro agr tumhe kisi bhi v1 k
    // index pe koi value mile jise choti value v2 me exist krti  ho (v[0] pe kregi
    // kyuki vhi sbse choti values hoti hai usse age use bdi bdi values hi milti
    // hai) to use swap kr do current v[i] ko v2[0] se aur  aisa krke hmne v2 ki
    // sbse choti value to hmne v1 me uski right jagah p phek dia hai aur ab v2[0] pe ab jo
    // new value hai vo pichli v[0] se bdi hai to  hme isko bhi iski right jagah pe thikane
    // lagana pdega by shifting it in right using insertion type approach
*/

// TC = O(n.m) SC = O(1)
void mergeTwoSortedOneWithSwapAndquickSortPartition(vector<int> &v1,  vector<int> &v2) {
  int i = 0, j = 0;
  while (i < v1.size()) {
    if (v1[i] > v2[j]) {
      swap(v1[i], v2[j]);       // Swap v1[i] and v2[0]
      quickPartitionShift(v2); // Reorganize v2 with the smallest at v2[0]
    }
    i++;
  }
}



int main() {
  vector<int> v1{0, 2, 4, 6, 8}, v2{1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  vector<int> ans(v1.size() + v2.size(), 0);

  // print before
  cout << "print before merge\n";
  // Print merged v1
  for (auto elm : v1) {
    cout << elm << " ";
  }
  cout << endl;

  // Print merged v2
  for (auto elm : v2) {
    cout << elm << " ";
  }
  cout << endl << "after merge" << endl;

  // Using default STL function to merge arrays (for reference)
  //   merge(v1.begin(), v1.end(), v2.begin(), v2.end(), ans.begin());

    // Custom function to merge two sorted arrays without extra space
  //   mergeTwoSortedOne_gap_method(v1, v2);

  mergeTwoSortedOneWithSwapAndquickSortPartition(v1, v2);
  // Print merged v1
  for (auto elm : v1) {
    cout << elm << " ";
  }
  cout << endl;

  // Print merged v2
  for (auto elm : v2) {
    cout << elm << " ";
  }

  return 0;
}
