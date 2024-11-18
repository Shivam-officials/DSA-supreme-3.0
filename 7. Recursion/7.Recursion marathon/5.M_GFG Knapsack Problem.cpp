// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


//TC = O(2^N) SC = O(N)
void knapsack(vector<int> &weights, vector<int> &profits, int capacity, int index, int currentProfit, int &maxProfit) {
  // Base case: If we've considered all items, update the maxProfit if the currentProfit is higher.
  if (index >= weights.size()) {
    maxProfit = max(currentProfit, maxProfit);
    return;
  }

  // Include the current item if it fits in the remaining capacity.
  if ((capacity - weights[index]) >= 0) {
    knapsack(weights, profits, capacity - weights[index], index + 1,
             currentProfit + profits[index], maxProfit);
  }

  // Exclude the current item and move to the next.
  knapsack(weights, profits, capacity, index + 1, currentProfit, maxProfit);
}

int main() {
    vector<int> profit{60, 100, 120}, weight{10, 20, 30};
    int capacity = 50;
    int maxProfit = 0;
//   vector<int> profit{1, 2, 3}, weight{4, 5, 1};
//   int capacity = 4;
//   int maxProfit = 0;
  knapsack(weight, profit, capacity, 0, 0, maxProfit);
  cout << maxProfit;

  return 0;
}
