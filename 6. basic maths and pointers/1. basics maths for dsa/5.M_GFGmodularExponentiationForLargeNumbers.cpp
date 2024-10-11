#include <iostream>
using namespace std;


/**
 //note: explanation ---> Intuition: This function efficiently calculates (x^n) % M using modular exponentiation by squaring. Direct computation of x^n can result in very large numbers that cause overflow. To avoid overflow and compute the result within a reasonable time, this method repeatedly squares the base while reducing the power (n) by half. If n is odd, we multiply the current result (ans) by the base (x), and always reduce everything modulo M to keep numbers small. This approach works in O(log n) time, much faster than a naive approach that takes O(n) time.
 */

long long int PowMod(long long int x, long long int n, long long int M) {
    long long ans = 1;  // Initialize the result to 1
    
    while (n > 0) {
        if (n & 1) {  // If n is odd
            ans = (ans * x) % M;  // Multiply current base with the result and take mod M
        }
        x = (x * x) % M;  // Square the base and take mod M
        n >>= 1;  // Right shift n to divide it by 2
    }
    
    return ans % M;  // Return the result modulo M
}

int main(int argc, char const *argv[])
{
    int base = 3,power = 2,mod = 4;
    cout << PowMod(base, power, mod);
    return 0;
}
