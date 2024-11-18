

#include <iostream>
#include <vector>
using namespace std;


// https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

//TC = O(2^N) SC = O(N)  

int countDerarrangement (int n) {
    // Base case: If there's only 1 item, it can't be deranged (no way to rearrange it to avoid its original position).
    if (n == 1) return 0;

    // Base case: For 2 items, there's exactly 1 way to derange them (swap them).
    if (n == 2) return 1;

    // Recursive case: INTUTION
    // To find the number of derangements for 'n' items:
    // 1. Choose a position for the nth item, such that it is NOT in its original position.
    //    There are (n - 1) choices for this.
    // 2. Now we have two cases:
    //    Case 1: Place the nth item in the position of item 'k' (where 'k' is any position other than 'n').
    //            This leaves us with a derangement problem for the remaining 'n-1' items.
    //    Case 2: Place the nth item in the position of item 'k' and move item 'k' to the original position of 'n'.
    //            This leaves us with a derangement problem for the remaining 'n-2' items.
    // Combine these cases with the recursive formula:
    // D(n) = (n - 1) * (D(n - 1) + D(n - 2))
    
    return (n - 1) * (countDerarrangement(n - 1) + countDerarrangement(n - 2));
}




int main()
{

    cout << countDerarrangement(4);
    
    return 0;
}


    