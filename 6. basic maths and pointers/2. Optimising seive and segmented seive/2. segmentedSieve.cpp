#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// helper function for returning the required base primes
vector<int> givePrimeSieveFrom2(int n) {
  vector<bool> sieve(n+1 , true);

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


// Note: We use the segmented sieve when we need to find primes within a very large range, especially when the upper bound (high) is extremely large, like 10^9. This is because we can't allocate arrays larger than 10^6 in the stack. Therefore, the difference between low and high should be manageable (e.g., up to 10^6).The segmented sieve divides the problem into smaller chunks to handle ranges efficiently.


// Intuition for segemented sieve:
// This function computes all prime numbers in the given range [low, high] using
// the segmented sieve approach.
// - First, it computes the primes up to sqrt(high) using a base sieve, because
// primes greater than sqrt(high) cannot have multiples within the range.
// - Then, it marks multiples of each base prime in the range [low, high] as
// non-prime.
// - Finally, it returns all the primes in the range by checking the remaining
// unmarked numbers.


// Time and Space Complexity:
    // - Base Sieve (to find primes up to sqrt(high)): O(sqrt(high) * log(log(sqrt(high))))
    // - Segmented Sieve (to mark primes in the range [low, high]): O((high - low) * log(log(high)))
    // - Overall Time Complexity: O(sqrt(high) * log(log(sqrt(high))) + (high - low) * log(log(high)))

    // Space Complexity:
    // - Base Sieve storage for primes up to sqrt(high): O(sqrt(high))
    // - Segmented Sieve storage for range [low, high]: O(high - low)
    // - Overall Space Complexity: O(sqrt(high) + (high - low))


// Code:
vector<int> primesInRangeUsingSieve(int low, int high) {

  // Get the base primes up to sqrt(high) using a sieve. bcz multiples of  those
  // are there in this range
  auto basePrimeSieve = givePrimeSieveFrom2(sqrt(high));

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
    firstMultiple = firstMultiple<low ? firstMultiple+prime : firstMultiple;

    // Ensure we start from prime * prime if it's greater.
    firstMultiple = max(firstMultiple, prime * prime);

    // Mark all multiples of the prime in the range as non-prime.
    while (firstMultiple <= high) {
      segmentedSieve[firstMultiple - low] = false;
      firstMultiple += prime;
    }
  }

  // Collect and return all primes in the range that are still marked as true.
  vector<int> ans_primesInRange;
  for (int i = 0; i < segmentedSieve.size(); i++) {
    if (segmentedSieve[i] == true) {
      cout << i + low <<"--debug point"<< endl;  
      ans_primesInRange.push_back(i + low);
    }
  }
  return ans_primesInRange;
}

int main(int argc, char const *argv[]) {
  int l = 110, h = 130;
    auto ans = primesInRangeUsingSieve(l, h);
    for (auto prime : ans) {
    cout << prime << " ";
    }
  return 0;
}
