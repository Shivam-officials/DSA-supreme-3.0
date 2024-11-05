#include <exception>
#include <iostream>
using namespace std;


// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// Tc = O(k^N) SC = O(N) k = number of faces N = dices

void numRollsToTargetRE(int n, int &k, int &target, int &count, int currentSum) {
    // Base case: if no dice left
    if (n == 0) {
        // Check if the current sum matches the target
        if (currentSum == target) count++;
        return;
    }

    // Recursive case: iterate through each face value of the die
    for (int i = 1; i <= k; i++) {
        // Recursively roll the remaining dice, adding the current face value to the sum
        numRollsToTargetRE(n - 1, k, target, count, currentSum + i);
    }
}


int numRollsToTargetRe_bySir_betterThoughtProcess(int n, int k, int target) {
    // Base case: If no dice left, check if target is 0 (1 way if true, 0 otherwise)
    if (n == 0) {
        return target == 0 ? 1 : 0;
    }

    int ways = 0;
    // Try each face value from 1 to k, recursively calculate ways for remaining dice
    for (int i = 1; i <= k; i++) {
        ways += numRollsToTargetRe_bySir_betterThoughtProcess(n - 1, k, target - i);
    }
    return ways;
}


int main(int argc, char const *argv[])
{
    int n = 2,k = 6,target = 7,count; //passed
    // int n = 1,k = 6,target = 3,count;   // passed
    // int n = 3,k = 6,target =  15,count = 0;   
    // int n = 30,k = 30,target = 500,count; // TLE

     numRollsToTargetRE(n ,  k,  target,count,0) ;
     cout << count<<endl;
     cout << numRollsToTargetRe_bySir_betterThoughtProcess(n, k, target);
    return 0;
}
