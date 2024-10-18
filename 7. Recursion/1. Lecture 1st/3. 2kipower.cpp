#include <iostream>
using namespace std;

//Time Complexity: O(n)
// Space Complexity: O(n)
int powerOfTwo(int n){

    // base case
    if(n == 0)
    {
        return 1;
    }

    // recursive relation
    return 2 * powerOfTwo(n-1);
    
}

int main(int argc, char const *argv[])
{
    cout << powerOfTwo(10);
    return 0;
}
