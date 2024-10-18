#include <iostream>
using namespace std;

//TC O(n) 
//SC O(n)
bool searchInArray(int *array, int size, int target, int index) {

  // base case
  if (index == size) {
    return false;
  }

  // processing
  if (array[index] == target) {
    return true;
  }
  // recursive call

  return searchInArray(array, size, target, ++index);
}

int main(int argc, char const *argv[]) {
  int arr[] = {10, 20, 30, 40, 50};
  int size = 5, target = 40;

  cout << searchInArray(arr, size, target, 0);
  return 0;
}
