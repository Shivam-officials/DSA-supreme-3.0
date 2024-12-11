#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

// In-place Merge Sort implementation with shifting for merging 
void merge(vector<int>& nums, int start, int mid, int end) {
    int i = start, j = mid + 1;

    // Compare elements from both halves and merge them in place using shifting
    while (i <= mid && j <= end) {
        if (nums[i] > nums[j]) {
            // Shift elements to the right to make space for nums[j]
            int index = j;
            int temp = nums[j];
            while (index > i) {
                nums[index] = nums[index - 1];
                index--;
            }

            nums[i] = temp; // Place nums[j] in its correct position
            j++;
            mid++; // Update mid since left half grows
        }
        i++;
    }

    // Commented code below uses swapping instead of shifting, which is less efficient 
    // due to multiple swaps required per misplaced element. and less swap is a lot overhead compared to shifiting for larget datasets for 
    // critical time complexity performance 
    // while(i <= mid && j <= end) {
    //     if (nums[i] > nums[j]) {
    //         for (int k = j; k > i; k--) {
    //             swap(nums[k], nums[k - 1]);
    //         }
    //         j++;
    //         mid++;
    //     }
    //     i++;
    // }
}

// note: MOST EFFICIENT IN PLACE MERGE SORT  OR MODIFIED SHELL SORT APPROACH
// gap method find the gap by halfing (ceil value of half) the size of array and then compare those in between length and if next value is bigger after that gap swap it and once one rotation is complete find the ceil value of half of that gap and repeat again.. it will magically sort it    

// TC = O(n log n) SC = O(1);
void merge2(vector<int> &nums, int start, int mid, int end) {
    // Calculate the initial gap for comparing elements
    int sizeOfArray = end - start + 1;
    int gap = sizeOfArray / 2 + sizeOfArray % 2;

    // Perform comparisons and swaps based on the gap
    while (gap > 0) {
        int i = start;
        int j = i + gap;

        // Traverse the array and compare elements with the given gap
        while (j <= end) {
            if (nums[j] < nums[i]) {
                // Swap elements if they are out of order
                swap(nums[j], nums[i]);
            }
            j++;
            i++;
        }

        // Reduce gap for the next iteration (ceil of half the current gap)
        gap = gap > 1 ? (gap / 2 + gap % 2) : 0;
    }
}

// TC = O(n log^2 n)  according to me for gap methods......... SC = O(1) ..
void mergeSort(vector<int>& nums, int start, int end) {
    if (start >= end) return; // Base case: Single element is already sorted

    int mid = (start + end) / 2;

    // Recursively sort left and right halves
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    // Merge the sorted halves in place
    merge2(nums, start, mid, end);
}

vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1); // Call merge sort on the entire array
    return nums; // Return the sorted array
}

int main(int argc, char const *argv[])
{
    vector<int>v{5,1,1,2,0,0};
    sortArray(v);
    for (auto &elm : v) {
     cout << elm<<" ";
    }
    return 0;
}
