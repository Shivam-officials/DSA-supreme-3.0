#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    char ch[100] = "shivam say my name";
    char *cptr =  ch;
    cout << ch<<endl;
    cout << &ch<<endl; //IMP
    cout << &ch[3]<<endl; //IMP
    cout << ch[0]<<endl;
    cout << cptr<<endl; //IMP
    cout << &cptr <<endl;
    cout << *cptr <<endl; //IMP
    cout << *(cptr+3) <<endl;

    cout << (cptr + 3)<<endl; //IMP if try to print any the address of the char array it will print the string from there on string of a address till end
    return 0;
}
