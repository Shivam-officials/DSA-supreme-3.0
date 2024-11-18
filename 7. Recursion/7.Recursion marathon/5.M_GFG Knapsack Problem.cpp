// https://www.geeksforgeeks.org/problems/0-1-knapsack1-problem0945/1

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


//TC = O(2^N) SC = O(N)
void knapsack1(vector<int> &weights, vector<int> &profits, int capacity, int index, int currentProfit, int &maxProfit) {
  // Base case: If we've considered all items, update the maxProfit if the currentProfit is higher.
  if (index >= weights.size()) {
    maxProfit = max(currentProfit, maxProfit);
    return;
  }

  // Include the current item if it fits in the remaining capacity.
  if ((capacity - weights[index]) >= 0) {
    knapsack1(weights, profits, capacity - weights[index], index + 1,
             currentProfit + profits[index], maxProfit);
  }

  // Exclude the current item and move to the next.
  knapsack1(weights, profits, capacity, index + 1, currentProfit, maxProfit);
}


//TC = O(2^N) SC = O(N)
int knapsack2(vector<int> &weights, vector<int> &profits, int capacity, int index) {

    /** base case one more way
        if(index == weights.size()-1 ){
            if (capacity-weights[index]>=0) {
                return profits[index];
            }else 
            {
                return 0;
            }
        }
        both base cases works just below is more intutive 

    */
    // Base case: No items left to process
    if (index == weights.size()) return 0;

    int includeProfit = 0;
    // Include current item if it fits in the remaining capacity
    if (capacity - weights[index] >= 0) {
        includeProfit = profits[index] + knapsack2(weights, profits, capacity - weights[index], index + 1);
    }

    // Exclude current item
    int excludeProfit = knapsack2(weights, profits, capacity, index + 1);

    // Return the maximum of including or excluding the current item
    return max(includeProfit, excludeProfit);
}


int main() {
    vector<int> profit{60, 100, 120}, weight{10, 20, 30};
    int capacity = 50;
    int maxProfit = 0;
//   vector<int> profit{1, 2, 3}, weight{4, 5, 1};
//   int capacity = 4;
//   int maxProfit = 0;
  knapsack1(weight, profit, capacity, 0, 0, maxProfit);
  cout << maxProfit<<endl;
  cout << knapsack2(weight, profit, capacity, 0);

  

  return 0;
}
