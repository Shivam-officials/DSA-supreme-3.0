#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printElement(int a) {
    cout<<a<<" ";
}


void sortAndRemoveDuplicates(vector<int> &v) {
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());

    v.erase(it,v.end());

    cout<<"vector has been sorted and duplicates have been removed\n";
}

int binarySearch(const std::vector<int> & v, int target) {
    int start = 0;
    int end = v.size()-1;

    while (start<=end) {
        auto middle = (start + end) /2;
        if (v[middle]==target) {
            return middle;
        }
        if (v[middle]< target) {
            start = middle+1;
        } else {
            end = middle-1;
        }
    }
    return -1;
}

int binarySearchInDecreasingOrder(const std::vector<int> & v, int target) {
    int start = 0;
    int end = v.size()-1;

    while (start<=end) {
        auto middle = (start + end) /2;
        if (v[middle]==target) {
            return middle;
        }
        if (v[middle]< target) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}

void binarySearch1stOccurance(const std::vector<int> & v, int target, int& indexFound) {
    int start = 0;
    int end = v.size()-1;
    indexFound = 0 ;
    while (start<=end) {
        int middle = (start + end) /2;
        if (v[middle]==target) {
            indexFound =  middle;
            end = middle - 1;

        }else if (v[middle]< target) {
            start = middle+1;
        } else {
            end = middle-1;
        }
    }
}


void binarySearchLastOccurance(const std::vector<int> & v, int target, int& indexFound) {
    int start = 0;
    int end = v.size()-1;
    indexFound = 0 ;
    while (start<=end) {
        int middle = (start + end) /2;
        if (v[middle]==target) {
            indexFound =  middle;
            start = middle + 1;

        }
        else if (v[middle]< target) {
            start = middle+1;
        } else {
            end = middle-1;
        }
    }
}
int main() {
    vector<int>v  = {10, 20,20,20, 30,30,30,30, 40, 50, 60,70,70,70, 70, 80, 90, 100,110};
    // sortAndRemoveDuplicates(v);
    // reverse(v.begin(), v.end());
    int target = 20;
    for_each(v.begin(), v.end(),printElement);
    cout<<endl;
    int indexFound ;
    binarySearchLastOccurance(v,target,indexFound);
    cout<<indexFound;
    return 0;
}
