#include <iostream>
using namespace std;

//Time Complexity: O(n)
// Space Complexity: O(n)
int sumOfNRecursion(int n) {
    // Base case: if n is 0, return 0
    // This is the stopping condition for the recursion.
    if (n == 0) { 
        return 0;
    }
    
    // Recursive call: calculate the sum of numbers from 1 to (n-1)
    // recAns will store the result of sumOfNRecursion(n - 1)
    int recAns = sumOfNRecursion(n - 1);
    
    // Add the current number (n) to the result from the recursive call
    int ans = n + recAns;
    
    // Return the sum of numbers from 1 to n
    return ans;
}


int main(int argc, char const *argv[])
{
    cout << sumOfNRecursion(5);
    return 0;
}
