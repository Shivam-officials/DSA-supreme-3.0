#include <iostream>
#include <vector>
#include <math.h>
using namespace std;




// note: this OPTIMISED way is used to return MAKE the SIEVE in which only prime number index will have true as a value  then u have to count print or whatever u want to do u can do with the sieve 

// complexity is same in the worst case bt in avg it will form better and faster
// TC = O(log(logn)) complexity is same bcz of the worst case 
// Sc = O(n) size of vector
vector<bool> countPrime(int n) {
  vector<bool> sieve(n, true);

  sieve[0] = sieve[1] = false;
  
  int ans = 0; 
  
  // for (int i = 2; i < n; i++) {
  for (int i = 2; i * i <= n; i++) { // OPTIMIZATION 2: Only loop up to sqrt(n) because multiples of i(5) below i*i like(5*4,5*3,5*2 etc) are already marked.
    if (sieve[i]) {

      // Mark all multiples of i as non-prime.

      // int j = i * 2;
      int j = i * i; // OPTIMISATION 1  -> Start marking multiples from i*i instead of i*2 to avoid redundant operations.
      while (j < n) {
        sieve[j] = false;
        j += i;  
      }

      //      OR below loop both are same just more redable

      // for(int j = i*i; j<n;j+=i){
      //   sieve[j] = false;
      // }

    }
  }
  
  return sieve;  // Return the count of primes less than n.
}


int main() {
  // int num = 21474836;
  int num = 24;
  auto sieve = countPrime(num);
  for (int i = 0; i<num; i++) {
  if (sieve[i]) {
    cout << i<<" ";
  }
  }
  return 0;
}
