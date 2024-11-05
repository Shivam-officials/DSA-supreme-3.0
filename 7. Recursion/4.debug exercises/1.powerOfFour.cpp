#include<iostream>
#include<vector>
using namespace std;


bool isPowerOfFour(int n) {
        if(n<=1){
        //    return false;
           return true;
        }
        if(n%4!=0){
           return false;
        }
       
        return isPowerOfFour(n/4);
}

int main(int argc, char const *argv[])
{
    cout << isPowerOfFour(64);
    return 0;
}
