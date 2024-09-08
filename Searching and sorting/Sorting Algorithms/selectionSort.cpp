#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// select the minimum element and set it at its right position
void selectionSort(vector<int> nums) {
int n = nums.size();
  for (int i = 0; i < n-1; i++) {
    int minIndex = i;
    // finding minimum element index
    for (int j = i+1 ; j < n; j++) {
      if (nums[j]<nums[minIndex]) {
        minIndex = j;
      }
    }
    // swaping it with its right position
    swap(nums[i], nums[minIndex]);
  }

  // printing sorted array
  for (int item : nums) {
    cout << item << endl;
  }
}

int main() {
  vector<int> v = {5, 4, 6, 53, 222,3, 2, 1, 22, 34,  11};
  selectionSort(v);
  return 0;
}