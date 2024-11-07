#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/coin-change/

// TC = O(n^amount) where n = coin's length 
// SC = O(amount)


int minCoinChange(vector<int> coins, int amount) {
  // Base case: If the amount is 0, no coins are needed
  if (amount == 0) {
    return 0;
  }

  // Initialize minCoins to a large value (INT_MAX) to find the minimum number of coins
  int minCoins = INT_MAX;

  // Iterate over each coin in the list
  for (auto coin : coins) {
    // Check if the current coin can be used (it should be less than or equal to the amount)
    if (coin <= amount) {
      // Recursive call to find the minimum coins required for the reduced amount (amount - coin)
      int recursionAns = minCoinChange(coins, amount - coin);

      // If the recursive call didn't return INT_MAX, it means a valid solution was found
      if (recursionAns != INT_MAX) {
        // Calculate the total coins used (1 for the current coin + coins needed for the remaining amount)
        int coinUsed = 1 + recursionAns;

        // Update minCoins to be the minimum of its current value and the coins used in this solution
        minCoins = min(minCoins, coinUsed);
      }
    }
  }

  // Return the minimum number of coins needed to make the given amount
  return minCoins;
}


int solve(vector<int>& coins, int amount) {
    //base case
    if(amount == 0) {
        //0 amount create krne k liye kitne coins
        return 0;
    }
    //if amount < 0
    int minCoinAns = INT_MAX;
    //hr amount k liye poore coins k array ko
    //traverse krre h 
    for(int i=0; i<coins.size(); i++) {
        //int amt = amount;
        int coin = coins[i];
        //if coin value > amount value, no need to call recursive function
        //if coin value <= amount value , call recursive fiunction
        if( coin <= amount) {
            //1 coin toh use hogya, amount becomes amount-coins
            //baaki reciursion sambhal lega
            int recursionAns = solve(coins, amount-coin);
            //ho skta h recursionAns valid ho ya fer Invalid 
            //invalid case -> recursionAns -> INT_MAX;
            //valid case -> recursionAns -> not equal to INT_MAX;
            if(recursionAns != INT_MAX) {
                //valid answer aaaya h 
                int coinsUsed = 1 + recursionAns;
                //kya above answer minimum hai
                minCoinAns = min(minCoinAns, coinsUsed);
            }

        }
    }
return minCoinAns;
}

// it goes 0 to amount ..... rest are amount to zero
int minCoinChange2(vector<int>coins,int initialAmount,int amount){
    if (initialAmount == amount) {
        return 0;
    }

    int minCoins = INT_MAX;
    for (auto coin : coins) {
        if (coin + initialAmount <= amount) {
            int recursionAns = minCoinChange2(coins, initialAmount+coin, amount);
            if (recursionAns == INT_MAX) continue;

            int coinUsed = 1+ recursionAns;

            minCoins = min(coinUsed,minCoins);
        }
    }
    return minCoins;
}

int main(int argc, char const *argv[]) {

  vector<int> cns{1, 2, 5};

  //note: if ans is not possible it will give INT_MAX as a ans u make a condition if function returns INT_MAX print -1 like below

  int ans =  minCoinChange(cns, 11);

  if (ans == INT_MAX) {
  cout << -1<<endl;
  }else 
  {
    cout << ans<<endl;
  }

  cout << solve(cns, 11)<<endl;
  cout << minCoinChange2(cns, 0,11)<<endl;
  return 0;
}
