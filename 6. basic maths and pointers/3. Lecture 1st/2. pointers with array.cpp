#include <iostream>
#include <vector>
using namespace std;

/** little explationation for pointer to an array from chatGPT for ptr variable down
 * When you dereference ptr using *ptr, you get the array itself (int[5]). It doesn't give the value of the first element; instead, it gives * the entire array {10, 20, 30, 40, 50}.
 * To access the first element's value, you need to dereference the array itself again:

   cout << (*ptr)[0] << endl;  // Output: 10
   Here, (*ptr)[0] accesses the first element of the array that ptr points to. 
 */

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50};
    // int (*ptr)[5] = &arr; // note: this makes ptr the pointer which points to the whole array or the array of size 5 ..... makes an pointer which stores the base address memory value of an array of size 5 in ptr ... kind of double pointer play intution is used here 
    int (*ptr) = arr; // note this just points to the base address of the value 
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
