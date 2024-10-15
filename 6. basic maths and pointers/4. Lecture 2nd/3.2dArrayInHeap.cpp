#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  // Stack allocation
  int a = 5;
  cout << a << endl;

  // Heap allocation
  int *p = new int; // 'new' allocates memory in the heap, returns the address
  *p = 5;
  cout << *p << endl;

  delete p; // Always manually free heap memory to avoid memory leaks

  // 2D array in the heap
  int **arr = new int*[4]; // Array of 4 int pointers (rows)

  for (int i = 0; i < 4; i++) {
      arr[i] = new int[4]; // Allocate 4 int elements for each row
  }

  cout << "Enter the data:" << endl;
  for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
          cin >> arr[i][j]; // Input data for 2D array
      }
  }

  cout << "Array data:" << endl;
  for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
          cout << arr[i][j] << " "; // Output 2D array data
      }
      cout << endl;
  }

  // Freeing allocated memory to prevent memory leaks
  for (int i = 0; i < 4; i++) {
      delete[] arr[i]; // Free each row
  }
  delete[] arr; // Free the main array

  int b[5] = {1,2,3,4,5};
  

  return 0;
}
