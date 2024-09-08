#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

//  Find odd occurring element:

// Conditions:

// A) All elements occur even no. of times except one.
// B) Element repeats itself in pairs.
// C) No pair repeats itself, no number can repeat/occur more than 2 times in a
// single stretch. D) Find element that occurs odd times.

// vector<int> v{1,1,2,2,3,3,4,5,5,3,3};

// by xor
int findOddTimesRepeatingElementByXor(vector<int> v) {
  int ans = 0;
  for (auto emnt : v) {
    ans ^= emnt;
  }
  return ans;
}

// by map
int findOddTimesRepeatingElementByHashmap(vector<int> v) {

  unordered_map<int, int> hashTable;
  for (auto elmt : v) {
    ++hashTable[elmt];
  }

  for (auto elmt : v) {
    if (hashTable[elmt] & 1) {
      return elmt;
    }
  }
  return -1;
}

// through binary search
// on intituion that every first index of pair will be on even number of index
// before unique element(non paired/single element)r and after unique element
// first index of pair will be on odd number of index
int findOddTimesRepeatingElementByBinarySerach(vector<int> v) {
  int start = 0;
  int end = v.size() - 1;
  int mid;

 // if there is only  1 element in the array
  if (v.size() == 1) {
    return v[0];
  }

  while (start <= end) {
    mid = start + (end - start) / 2;
    int firstIndex;

    // its not in the pair 
    if ((mid > 0) && (v[mid] != v[mid - 1]) && (mid < v.size() - 1) &&
        (v[mid] != v[mid + 1])) {
      return mid;
    }

    // edge cases to avoid out of bound error if its on 0th index
    if (mid == 0 && v[mid] != v[mid + 1]) {
      return 0;
    }

    // edge case to avoid out of bound error if its on last index
    if (mid == v.size() - 1 && v[mid] != v[mid - 1]) {
      return v.size() - 1;
    }

    // finding the first index of pair
    if (v[mid] == v[mid + 1]) {
      firstIndex = mid;
    } else {
      firstIndex = mid - 1;
    }

    /// shift start / end accordign to condition
    if (firstIndex & 1) {
      // end = mid-1;
      end = firstIndex - 1;
    } else {
      // start = mid+1;
      start = firstIndex + 2;
    }
  }

  return -1;
}

int main() {
  vector<int> v{
      5, 1, 1, 2, 2, 3, 3, 5, 5, 3, 3,
  };

  cout << findOddTimesRepeatingElementByBinarySerach(v);

  return 0;
}
