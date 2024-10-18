#include <climits>
#include <iostream>
using namespace std;

//TC = O(n) SC = O(n)
void individualDigits(int num){
    // base case
    if(num == 0) return ;

    
    // recursive call .... baki k case recursion solve kr dega
    individualDigits(num/10);  // head recursion bcz we want the order in reverse order

    // processing ek case hum krenge
    cout << num%10 <<" ";    
}

int main(int argc, char const *argv[])
{
    int num = 389;
    individualDigits(num);
    return 0;
}
