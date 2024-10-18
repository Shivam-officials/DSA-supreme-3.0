#include <climits>
#include <iostream>
#include <vector>
using namespace std;

//TC = O(n) SC = O(n)
void minInArrayRecursive(vector<int> array, int size, int index, int &ans) {

  // base condition
  if (index == size)
    return;
  // processing ... 1 case hmne solve kia
  if (array[index] < ans)
    ans = array[index];

  // recursive call ... baki k case recursion dekh lega
  minInArrayRecursive(array, size, index + 1, ans);

  // return ans;
}

int main(int argc, char const *argv[]) {
  vector<int> arr{40, 50, 20, 60, 10, 30, -33};

  int ans = INT_MAX;
  minInArrayRecursive(arr, arr.size(), 0, ans);
  cout << ans;
  return 0;
}
