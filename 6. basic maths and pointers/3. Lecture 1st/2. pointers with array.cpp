#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50};
    int * ptr = arr;

    cout << arr<<endl;
    cout << &arr<<endl; //IMP
    cout << arr[0]<<endl;
    cout << &arr[0]<<endl; //IMP
    cout << ptr<<endl;
    cout << &ptr<<endl;
    cout << *ptr<<endl;

    cout << *arr + 1<<endl; //IMP
    cout<<*(arr + 1)<<endl; //IMP
    cout<<*(arr+3)<<endl;



 

    return 0;
}
