#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5;
    int* ptr = &a;
    

    // cout << a<<endl;
    // cout << &a<<endl;
    // cout << ptr<<endl;
    // cout << &ptr<<endl;
    // cout << *ptr<<endl;

    char b = '4';
    char * cptr = &b;
    cout << sizeof(cptr)<<" "<<sizeof(ptr); 

    // 
    int* sptr = 0;
    cout << sptr;
}
