#include <iostream>
#include <vector>
using namespace std;

// question
double myPow(double x, int n) {

       int p = abs(n);
       double ans = 1.0;
       while(p>=1){
        
          p /= 2 ;
          x *= x;
       }
       return n<0 ? 1/ans : ans;    
}


// ans
double myPowAns(double x, int n) {

       int p = abs(n);
       double ans = 1.0;
       while(p>=1){
        if(p&1) ans *= x;
          p /= 2 ;
          x *= x;
       }
       return n<0 ? 1/ans : ans;    
    }
int main(int argc, char const *argv[])
{
    cout << myPowAns(5, 4);
    return 0;
}
