#include <iostream>
using namespace std;


//Time Complexity: O(2^n)
// Space Complexity: O(n)
int fibonacci(int n) {
    // Base case: if n is 0 or 1, return n (because F(0) = 0 and F(1) = 1)
    if (n == 0 || n == 1) {
        return n;
    }

    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main(int argc, char const *argv[])
{
    cout << fibonacci(5);
    return 0;
}
