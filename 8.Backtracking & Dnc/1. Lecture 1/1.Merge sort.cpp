#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


void print(int a){
    cout << a <<" ";
}

// TC = O(N) Sc = O(N)
void mergeWithSorting(std::vector<int>& nums, int start, int end) {
    int mid = (start + end) / 2;

    // Using std::vector for temporary arrays (recommended)
    std::vector<int> leftSide{nums.begin() + start, nums.begin() + mid + 1};  // includes element at mid
    std::vector<int> rightSide{nums.begin() + mid + 1, nums.begin() + end + 1};  // includes element at end

    // Alternative using dynamic arrays (not recommended due to manual memory management)
    /*
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    int* leftSide = new int[leftSize];
    int* rightSide = new int[rightSize];

    // Copy elements into leftSide and rightSide
    std::copy(nums.begin() + start, nums.begin() + mid + 1, leftSide);
    std::copy(nums.begin() + mid + 1, nums.begin() + end + 1, rightSide);
    */

    int li = 0, ri = 0, index = start;

    // Merging process
    while (li < leftSide.size() && ri < rightSide.size()) {
        if (leftSide[li] < rightSide[ri]) {
            nums[index++] = leftSide[li++];
        } else {
            nums[index++] = rightSide[ri++];
        }
    }

    // Copy any remaining elements from leftSide
    while (li < leftSide.size()) {
        nums[index++] = leftSide[li++];
    }

    // Copy any remaining elements from rightSide
    while (ri < rightSide.size()) {
        nums[index++] = rightSide[ri++];
    }

    // If using dynamic arrays, free the memory after merging
    /*
    delete[] leftSide;
    delete[] rightSide;
    */
}

//note: inplace with gap method is best and fastest go in dnc assignment 

// Function to merge two sorted subarrays in-place 
//TC =  O(n^2)  SC = O(1)
void inPlaceMerge(std::vector<int>& nums, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end) {
        // If the left element is smaller or equal, no merge needed for this element
        if (nums[left] <= nums[right]) {
            left++;
        } else {
            // Element at 'right' is smaller than 'left', swap and shift
            int temp = nums[right];
            // Shift all elements between 'left' and 'right' to the right
            for (int i = right; i > left; i--) {
                nums[i] = nums[i - 1];
            }
            // Place the element from 'right' into its correct position
            nums[left] = temp;

            // Move both pointers forward
            left++;
            mid++;
            right++;
        }
    }
}




// TC =  O(n log n)   ... Recursive depth is log(n), with O(n) merging at each level
// SC = O(n)
//   - O(n) for temporary arrays to hold left and right halves... on each level
//   - O(log n) for recursive call stack, but dominated by O(n) for temporary arrays

void mergeSort(std::vector<int>& nums, int start, int end) {
    // Base case
    if (start >= end) { // start == end will also do the job its start>= end for extra care
        return;
    }

    // Find the midpoint
    int mid = (start + end) / 2;

    // Recursively sort the left and right halves
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    // Merge the sorted halves
    mergeWithSorting(nums, start, end);  // if used this then the TC = O(n log n) Sc = O(N)

    // inPlaceMerge(nums, start, mid, end);  // if used this then the TC = O(n^2 log n) Sc = O(Log(n))
}

int main() {
    vector<int> nums {20,40,60,10,90,70,30,90,100,50};
    for_each(nums.begin(), nums.end(), print);
    mergeSort(nums, 0, nums.size() - 1);
    cout << endl<<"after"<<endl;
    for_each(nums.begin(), nums.end(), print);
    return 0;
}

