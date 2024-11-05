#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/


//note:Intuition: Traverse the array. If we find a price lower than the current minPrice, update minPrice.
// Otherwise, calculate the profit for today's price, and if it's more than maxProfit, update maxProfit.


// Time Complexity: O(n), where n is the number of elements in the prices array.
// Space Complexity: O(n), due to the recursion depth.
void maxProfitRE(vector<int> &prices, int i, int &minPrice, int &maxProfit) {
  // Base case: If we have reached the end of the prices array, terminate the recursion
  if (i == prices.size()) 
    return;

  // Check if the current price is less than the minimum price encountered so far
  if (prices[i] < minPrice) 
    minPrice = prices[i]; // Update the minimum price

  // Calculate the profit if we were to sell at the current price
  int currentProfit = prices[i] - minPrice;

  // Update maxProfit if the currentProfit is greater than the previous maxProfit
  if (currentProfit > maxProfit) 
    maxProfit = currentProfit;

  // Recursively call the function for the next index in the array
  return maxProfitRE(prices, i + 1, minPrice, maxProfit);
}

int maxProfitItertive(vector<int> prices) {
    int minPrice = INT_MAX, maxProfit = INT_MIN;

    // Iterate over each price in the array
    for (auto price : prices) {
        // Update minPrice if the current price is lower
        if (price < minPrice) 
            minPrice = price;

        // Calculate today's profit based on the current price and minPrice
        int todaysProfit = price - minPrice;

        // Update maxProfit if today's profit is higher than the previously recorded maxProfit
        if (todaysProfit > maxProfit) 
            maxProfit = todaysProfit;
    }

    // Return the maximum profit calculated
    return maxProfit;
}


int main(int argc, char const *argv[]) {
  vector<int>pricesOfStock {7,1,5,3,6,4};
//   vector<int> pricesOfStock{2, 4, 1};
  int minPrice = INT_MAX, maxProfit = INT_MIN;

  maxProfitRE(pricesOfStock, 0, minPrice, maxProfit);
  cout << maxProfit<<endl;

  cout << maxProfitItertive(pricesOfStock)<<endl;
  return 0;
}
