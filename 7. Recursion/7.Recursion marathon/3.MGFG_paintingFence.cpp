

#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

//TC = O(2^N) SC = O(N)
int countWays(int n, int k) {
    // Base case 1: If there is only 1 fence, there are 'k' ways to paint it (any of the k colors can be chosen).
    if (n == 1) return k;

    // Base case 2: If there are 2 fences, 
    // - We can paint them the same color in 'k' ways.
    // - We can paint them different colors in 'k * (k - 1)' ways.
    // Total ways = k + k * (k - 1).
    if (n == 2) return k + k * (k - 1);

    // Recursive case:
    // To paint the nth fence:
    // - If the nth fence has a *different* color from the (n-1)th fence:
    //   There are (k - 1) ways to choose a color for the nth fence. 
    //   The remaining fences (1 to n-1) can be painted in 'countWays(n-1, k)' ways.
    //
    // - If the nth fence has the *same* color as the (n-1)th fence:
    //   The nth and (n-1)th fences together must have a different color from the (n-2)th fence.
    //   There are (k - 1) ways to paint the nth and (n-1)th fences in such a scenario.
    //   The remaining fences (1 to n-2) can be painted in 'countWays(n-2, k)' ways.
    //
    // Total ways = (k - 1) * (countWays(n-1, k) + countWays(n-2, k)).
    return (k - 1) * (countWays(n - 2, k) + countWays(n - 1, k));
}


int main()
{

    cout << countWays(4, 3); // passed bcz right ans = 66 = excpected ans
    
    return 0;
}