#include <iostream>

using namespace std;


int getFactorial(int n){

    // base case
    if(n ==0 || n==1)
    {
        return 1;
    }
    
    // recursive relation
    int recusrsionAns = getFactorial(n-1);

    // processing 
    return n * recusrsionAns;

}

int main(int argc, char const *argv[])
{
    cout << getFactorial(5);
    return 0;
}
