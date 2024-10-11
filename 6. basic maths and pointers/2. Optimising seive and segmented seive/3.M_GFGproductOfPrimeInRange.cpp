#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


// https://www.geeksforgeeks.org/problems/product-of-primes5328/1

vector<int> givePrimeSieveFrom2(int n) {
  vector<bool> sieve(n , true);

  sieve[0] = sieve[1] = false;

  vector<int> ansSieve;

  for (int i = 2; i <= sqrt(n ); i++) {
    if (sieve[i]) {

      int j = i * i;
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

  // making the array which only contains primes fromt the sieve
  for (int i = 2; i < sieve.size(); i++) {
    if (sieve[i]) {
        cout << i<<"--debug point"<<endl;
      ansSieve.push_back(i);
    }
  }

  return ansSieve; // Return the list of primes up to n.
}


vector<int> primesInRangeUsingSieve(int low, int high) {

  // Get the base primes up to sqrt(high) using a sieve. bcz multiples of  those
  // are there in this range
  auto basePrimeSieve = givePrimeSieveFrom2(sqrt(high)+1);

  // Initialize a boolean vector to mark primes in the range [low, high].
  vector<bool> segmentedSieve(high - low + 1, true);

  // Special case: If low is 1, mark it as non-prime since 1 is not prime.
  if (low == 1) {
    segmentedSieve[0] = false;
  }

  // For each base prime, mark its multiples in the range as non-prime.
  for (auto prime : basePrimeSieve) {
    // Calculate the first multiple of the prime within the range.
    int firstMultiple = (low / prime) * prime;
    if (firstMultiple < low) {
      firstMultiple += prime;
    }

    // Ensure we start from prime * prime if it's greater.
    firstMultiple = max(firstMultiple, prime * prime);

    // Mark all multiples of the prime in the range as non-prime.
    while (firstMultiple  <= high) {
      segmentedSieve[firstMultiple - low] = false;
      firstMultiple += prime;
    }
  }

  // Collect and return all primes in the range that are still marked as true.
  vector<int> ans_primesInRange;
  for (int i = 0; i < segmentedSieve.size(); i++) {
    if (segmentedSieve[i] == true) {
      cout << i + low << "--debug point"<<endl;
      ans_primesInRange.push_back(i + low);
    }
  }
  return ans_primesInRange;
}

long long primeProduct(long long L, long long R){
      auto ans = primesInRangeUsingSieve(L, R);
  long long productModule = 1;
  for (auto prime : ans) {
    productModule = (productModule * prime) % (10000000 + 7);
  }
  return productModule;
}

int main()
{
    int l = 1 , h = 20;
    cout << primeProduct(l, h);
    return 0;
}
