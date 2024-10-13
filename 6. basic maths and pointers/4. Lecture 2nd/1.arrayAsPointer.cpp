#include <iostream>
using namespace std;


void test(int  arr[] , int size){
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
}


int main(int argc, char const *argv[])
{
    int arr[] {10,20,30};
    cout <<arr[0]<<" "<< arr[1]<<" "<<arr[2]<<endl;
    test(arr, 3); // note: array is always passed by reference and vector is always passed by value by defualt u can pass vecotr by refernce using & in parameter in function signature
    cout <<arr[0]<<" "<< arr[1]<<" "<<arr[2];

    return 0;
}
