#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50};
    // int (*ptr)[5] = &arr; // note: makes the pointer which points to the whole array or the array of size 5 ..... makes an pointer which stores the base address memory value of an array of size 5 in ptr 
    int (*ptr) = arr;
    // cout << *ptr[0] <<" "<<*((*ptr)+1)<<endl; // 10 20
    cout << *ptr<<endl; // 10
    int *ptr2 = arr;

    cout << arr<<endl;
    cout << &arr<<endl; //IMP
    cout << arr[0]<<endl;
    cout << &arr[2]<<endl; //IMP
    cout << ptr<<endl;
    cout << &ptr<<endl;
    cout << *ptr<<endl;

    cout << *arr + 1<<endl; //IMP
    cout<<*(arr + 1)<<endl; //IMP
    cout<<*(arr+3)<<endl;

    
 

    return 0;
}
