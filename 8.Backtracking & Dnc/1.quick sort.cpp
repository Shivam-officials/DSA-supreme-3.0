#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;


/**
 *Average Time Complexity: O(n log n)
 *Worst-Case Time Complexity: O(n²)
 *Space Complexity: O(log n) on average, O(n) in the worst case.
*/

void quickSort(int arr[], int size, int start, int end) {
    int pivot = end;      // Choose the last element as the pivot
    int i = start - 1;    // Index for smaller element
    int j = start;

    if (start >= end) {   // Base case: no elements to sort
        return;
    }

    while (j < pivot) {   // Partitioning loop
        if (arr[j] < arr[pivot]) { // If current element is smaller than pivot
            ++i;
            swap(arr[i], arr[j]);  // Swap with element at i
        }
        j++;
    }
    ++i;
    swap(arr[i], arr[pivot]);      // Place pivot in correct position
    quickSort(arr, size, start, i - 1); // Recur for left subarray
    quickSort(arr, size, i + 1, end);   // Recur for right subarray
}



void quickSortPractice(vector<int> &nums,int start , int end){
    // base case 
    if(start>=end) return;


    // int i = start-1 ; // version 1
    int i = start ; // version 2
    int j = start;
    int pivot = end;

    while(j<pivot){
        if(nums[j]<nums[pivot]){
            // ++i; version 1
            swap(nums[i],nums[j]);
            i++; // version 2
        } 
        j++;
    }
    // ++i; version 1
    swap(nums[i],nums[pivot]);
    quickSortPractice(nums, start, i-1);
    quickSortPractice(nums, i+1, end);
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 6, 8, 10, 1, 2, 1}; // avg case
    int arr2[] = {1, 2, 3, 4, 5, 6, 7}; // worst case
    vector<int> nums {100,30,50,10,20,90,60,80,70,40};
    for (auto  it: nums) {
        cout << it << " ";
    }

    // quickSort(arr,8,0,7);
    quickSortPractice(nums, 0, nums.size()-1);
    
    cout << endl << "after"<<endl;
    for (auto  it: nums) {
        cout << it << " ";
    }
    return 0;
}
