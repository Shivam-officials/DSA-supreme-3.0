#include <iostream>
#include <vector>
using namespace std;


// intution : for every iteration untill the element at i th  value is smaller than its previous value continue swapping it with previous value
void insertionSort(vector<int> v) {

    //outer loop
    for(int i = 1; i <= v.size()-1; i++)
    {   
        // iterate from i to 1 index to swap untill it is smaller than its previous value
        for (int j = i; j>0; j--) {
            
            // swap if j is smaller its previous value  
            if(v[j] < v[j-1])
            {
             swap(v[j],v[j-1]);
            }
            
        }
        
    }
    

  // printing sorted array
  for (int item : v) {
    cout << item << endl;
  }
}

int main() {

  vector<int> v = {5, 4, 6, 3, 2, 1};

insertionSort(v);
  return 0;
}