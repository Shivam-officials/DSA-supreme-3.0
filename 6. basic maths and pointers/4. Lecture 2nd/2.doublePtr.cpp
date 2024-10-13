#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 34;
    int * ptr = &a;
    // int *ptr2 = ptr;
    int **ptr2 = &ptr; //note: for strong the address of a pointer we have to ** its also called double pointer
    **ptr2 = 34;  // pointer to a int */pointer [int* = pointer to a int]
    cout << ptr2<<endl;
    cout << *ptr2<<endl;
    cout << **ptr2<<endl;
    return 0;
}
