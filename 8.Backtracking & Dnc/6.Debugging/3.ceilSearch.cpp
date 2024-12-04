#include <iostream>
using namespace std;

// gives the index of ceil value of target ... BELOW ONE BS approach will be more intutive and easy 
int ceilSearch(int arr[], int low, int high, int x) {
	int mid;
	// if (x < arr[low])
	if (x <= arr[low])
		return low;
	// if (x >= arr[high])
	if (x > arr[high])
		return -1;
	mid = (low + high) / 2;
	if (arr[mid] == x)
		return mid;
	else if (arr[mid] < x) {
		// if (mid + 1 < high && x < arr[mid + 1]) // yha bhi bhul gya tha 
		if (mid + 1 <= high && x <= arr[mid + 1])
			return mid + 1;
		else
			return ceilSearch(arr, mid + 1, high, x);
	}
	else {
		// if (mid - 1 > low && x >= arr[mid - 1]) // ye yha mai bhul gya tha
		if (mid - 1 >= low && x >= arr[mid - 1])
			return mid;
		else
			return ceilSearch(arr, low, mid - 1, x);
	}
}


int binarySearchCeil(int arr[],int target){
    int low = 0,high = 4,mid = 0;
    
    // edge cases
    if(target > arr[high])return -1;
    if(target <= arr[low])return low ;


    while(low<high){
        mid = (low + high)/2;
        if(arr[mid]== target) return mid;
        if(arr[mid]< target)
        {
            low = mid+1;
        }else 
        {
            high = mid;
        }
        
    }
    return low;
}

int main(int argc, char const *argv[])
{
    int arr[]{2,4,6,8,10};
    int target = 10;
    cout << ceilSearch(arr, 0, 4, target)<<endl;
    cout << binarySearchCeil(arr, target);
    return 0;
}
