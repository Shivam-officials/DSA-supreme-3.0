#include <iostream>
#include <vector>
using namespace std;

// TC = O(N^2)  SC = O(N)
void printSubArrayRE(vector<int>&arr,int start, int end){
    // base case
    if(end == arr.size()) return;
    // 1 case
    for (int i = start; i <=end ; i++) {
        cout << arr[i]<<" ";
    }
    cout << endl<< endl;

    printSubArrayRE(arr, start, end+1);
}

void printAllSubArrayRE(vector<int>&arr){
    for (int start = 0; start <arr.size(); start++) {
        int end = start;
        printSubArrayRE(arr, start, end);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums{0,1,2,3,4,5};
    printAllSubArrayRE(nums);
    return 0;
}
