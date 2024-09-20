#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> v) {
 int n = v.size();
//outer loop for n[size of vector] times iterations 
  for (int i = 0; i < n-1; i++) {

    // on every iteration the biggest element will be on the last , last 2nd last 3rd and so on;
    for (int j = 1; j <= n - 1 - i; j++) {
      if (v[j] < v[j - 1]) {
        swap(v[j], v[j - 1]);
      }
    }
  }

//printing sorted array
  for (int item : v) {
    cout << item << endl;
  }
}

int main() {
  vector<int> v = {5, 4, 6, 3, 2, 1};
  bubbleSort(v);
  return 0;
}
