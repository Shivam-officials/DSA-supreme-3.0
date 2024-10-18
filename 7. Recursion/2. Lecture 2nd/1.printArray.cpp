#include <iostream>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(n)
void printArray(int *array , int size,int index){
   if(index == size) // base case
   {
    return;
   }

   // processing 
   cout << array[index++]<<" ";

   // recursive call
   printArray(array, size, index);
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50};
     printArray(arr,5,0);
    return 0;
}
