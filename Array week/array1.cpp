//
// Created by shivam on 05-07-2024.
//

#include <algorithm>
#include <iostream>
using namespace std;
void showArray( int a[], const int length) {
    for (int i = 0; i < length; ++i) {
        cout<<a[i]<< " ";
    }
    cout << endl;
}


void linearSearch(const int  arr[], const int element) {
    for (int index = 0; index < 10; ++index) {
        if (arr[index] == element) {
            cout<<"element found at "<<index <<endl;
            return;
        }
    }
    cout<<"element doesnt found "<<endl;
}

void findMin(int * arr, int size) {
    int min = INT_MAX ;
    for (int i = 0; i < size; ++i) {
        if(arr[i] < min) {
            min = std::min(min,arr[i]);
        }
    }
    cout<<min;
}

void count0sand1s(const int * arr,int size) {
    int zeros = 0,ones = 0;
    for (int index = 0; index < size; ++index) {
        if (arr[index]==0) {
            zeros++;
        }else if(arr[index] == 1) {
            ones++;
        }
    }
    cout<<"zeroes are the "<<zeros<<" \n ones are "<<ones<<endl;
}

void doExtremePrinting(int * arr, int size_of_array) {
    /** my way */
    int start = 0;
    int end = size_of_array-1;
    for (int i = 0; i < size_of_array; ++i) {
        if (i&1) {
            cout<<arr[end]<<" ";
            end--;
        } else {
            cout<<arr[start]<<" ";
            start++;
        }
    }

    // /** sir way */
    // while (start<=end) {
    //     if (start == end) {
    //         cout<< arr[start]<<" ";
    //         start++;
    //     } else {
    //         cout<<arr[start]<<" ";
    //         start++;
    //
    //         cout<<arr[end]<<" ";
    //         end--;
    //     }
    //
    // }
}

void swapWithTemp(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void swapWithXor(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

void swapWithPlusMinus(int &a, int &b) {
    a = a+b;
    b = a-b;
    a = a-b;
}

void swapToNumbers(int n1, int n2) {
    cout<<"before swapping \n n1 is "<< n1 << "\n and n2 is "<< n2;

    // swapWithTemp(n1, n2);

    // swapWithXor(n1, n2);

    // swapWithPlusMinus(n1,n2);
    swap(n1,n2);

    cout<<"\n after swapping \n n1 is "<< n1 << "\n and n2 is "<< n2;


}

void reverseArray(int * arr, int size_of_array) {
    // //my way
    // for (int index = 0; index < size_of_array/2; ++index) {
    //     //swapping number with default function
    //     swap(arr[index],arr[size_of_array-index-1]);
    // }

    // sir way
    int low = 0;
    int high = size_of_array-1;
    while (high>low) {
        swap(arr[low++],arr[high--]);
    }

    // // defualt function to reverse it
    // reverse(arr,arr+size_of_array);
}

int main() {
    int a[] = {10,20,30,40,50,60,70,80,90,100,110};
    int sizeOfArray = sizeof(a)/sizeof(int); // size(array_name) fn returns the size of array
    // //fills the array with value till specified  index n (n index not included)
    // fill_n(a+2,size(a),1);
    //
    // // fills the value from specifed begin to end address
    // fill(a+5,end(a),0);
    // //reducing something from address like 5 above will
    // //reduce the make it go backword  to 5 times like end address to 5th element address
    //
    // // same as previous only it uses begin and end to find about the address of array
    // fill(begin(a)+size(a)/2,end(a),35 );

    showArray(a,sizeOfArray);
    cout<<"-------------------"<<endl;
    int e = 295;

    // linearSearch(a,e);
    // cout<<"---"<<size(a)<<"------";

    // findMin(a,size(a));

    // count0sand1s(a,size(a));

    // doExtremePrinting(a,sizeOfArray);

    // int n1 = 10,n2 = 20;
    // swapToNumbers(n1,n2);


    // reverseArray(a,sizeOfArray);
        // reverse(a,a+11);
    showArray(a,sizeOfArray);
    // cout<<(-10<<2);
    return 0;
}

