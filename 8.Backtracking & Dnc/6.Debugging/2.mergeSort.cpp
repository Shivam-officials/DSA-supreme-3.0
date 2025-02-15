#include <iostream>
using namespace std;


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

void merge_sort(int arr[], int start, int end) {
    // base case
    if(start>=end)return; //Note:base case was also missing

    int mid = (start + end) / 2;
    // merge_sort(arr, start, mid-1);
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,2,4,3,8,1,5,7,6,9};

    cout << "before sort"<<endl;
    for (auto elm : arr) {
     cout << elm << " ";
    }
    merge_sort(arr, 0, 9);
    cout << "\nafter sort"<<endl;
    for (auto elm : arr) {
     cout << elm << " ";
    }
    return 0;
}
