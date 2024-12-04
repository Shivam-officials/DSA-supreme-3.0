#include <iostream>
using namespace std;


// merge two sorted array in sorted one OR sort the mountain array
void merge(int arr[10], int start, int mid, int end) {
    int left[mid - start + 1];
    int right[end - mid];
    // for (int i = 0; i < mid - start; i++) {
    for (int i = 0; i <= mid - start; i++) {
        left[i] = arr[start + i];
    }
    // for (int j = 0; j <= end - mid; j++) {
    for (int j = 0; j < end - mid; j++) {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    // while (i < mid - start || j < end - mid) {
    while (i <= mid - start && j < end - mid) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // while (i < mid - start) {
    while (i <= mid - start) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // while (j <= end - mid) {
    while (j < end - mid) {
        arr[k] = right[j];
        j++;
        k++;
    }
}



int main(int argc, char const *argv[])
{
    int arr[] = {1,3,5,7,9,2,4,6,8,10};
    merge(arr, 0, 4, 9);
    for (auto elm : arr) {
     cout << elm <<" ";
    }
    return 0;
}
