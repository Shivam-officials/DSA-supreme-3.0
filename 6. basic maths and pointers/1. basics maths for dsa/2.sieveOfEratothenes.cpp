#include <iostream>
#include <vector>
using namespace std;


/**
 * @explanation: 
 * just make every number prime at first except 0,1 
 * and then visit a number if its prime count it and make its multiple non - prime and repeat 
 */


// TC = O(N *log(log(N))) its bcz of inner loop which running n/2 + n/3 + n/4 +......... == n * log(log(n)) 
// SC = O(N) because of the boolean array prime[].
int countPrime(int n) {
  // Create a boolean vector to mark prime numbers. Initially assume all are prime.
  vector<bool> prime(n, true);

  // Mark 0 and 1 as non-prime since they are not prime numbers.
  prime[0] = prime[1] = false;
  
  int ans = 0;  // Variable to store the count of prime numbers.
  
  // Iterate through all numbers from 2 to n-1.
  for (int i = 2; i < n; i++) {
    // If the number is still marked as prime
    if (prime[i]) {
      ans++;  // Increment the prime count.

      // Mark all multiples of i as non-prime.
      int j = i * 2;
      while (j < n) {
        prime[j] = false;
        j += i;  // Move to the next multiple of i.
      }

      //      OR below loop both are same just more redable

      // for(int j = i*2; j<n;j+=i){
      //   prime[j] = false;
      // }
    }
  }
  
  return ans;  // Return the count of primes less than n.
}


int main() {
  // int num = 21474836;
  int num = 25;
  cout << countPrime(num);
  return 0;
}
