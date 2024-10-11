#include <iostream>
#include <math.h>
using namespace std;

//note: check upto strt(n) for finding its prime or note bcz if its not prime it will definately have a factor below its sqrt(n)


// idea: METHOD 1is really easy make the below loop to go till <n (i<n) instead of i<=sqrt(n)

bool isPrime_Method2(int &a){
    for(int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0) {
            return false;
        }
    }
    
    return true;
}


// TC = O( N * sqrt(N) ) sc = O(1);
int countPrime(int a){
    int count = 0;
    for (int i = 2; i < a; i++) {
        if (isPrime_Method2(i)) {
        count++;
        cout << i<<endl;
        }
    }
    cout<<"---------------"<<endl;
    return count;
}

int main(int argc, char const *argv[])
{
    int at = 21;
    
   cout << countPrime(at);

    
    return 0;
}
