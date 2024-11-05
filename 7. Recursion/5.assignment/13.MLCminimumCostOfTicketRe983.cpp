#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;


//INTUTION note: ??

// TC = O(3^N)  SC = O(N) where N is the length of days array
int mincostTicketsRe_ME_With_Chatgpt_Help_At_Last(vector<int> days, vector<int> cost, int index) {
  // Base case: If the current index is beyond the last travel day, no further
  // cost is needed.
  if (index >= days.size())
    return 0;

  int ans = INT_MAX;

  // Iterate over each type of ticket cost (1-day, 7-day, and 30-day pass).
  for (int i = 0; i < cost.size(); i++) {
    int allowedDays = 0;

    // Calculate the end day up to which the current ticket type will cover.
    if (i == 0) {
      // 1-day pass covers only the current day.
      allowedDays = days[index] + 1;
    } else if (i == 1) {
      // 7-day pass covers the next 7 days from the current day.
      allowedDays = days[index] + 7;
    } else {
      // 30-day pass covers the next 30 days from the current day.
      allowedDays = days[index] + 30;
    }

    int allowedDayAfterIndex = index;

    // Move allowedDayAfterIndex to skip all days covered by the current pass.
    // This loop stops at the first day not covered by the pass.
    while (allowedDayAfterIndex < days.size() &&
           days[allowedDayAfterIndex] < allowedDays) {
      allowedDayAfterIndex++;
    }

    // Recursive call to calculate the minimum cost starting from
    // allowedDayAfterIndex.
    int moneyUsed =
        cost[i] + mincostTicketsRe_ME_With_Chatgpt_Help_At_Last(days, cost, allowedDayAfterIndex);

    // Track the minimum cost among all ticket options.
    ans = min(ans, moneyUsed);
  }

  return ans;
}

int mincostTicketsSir_compact_more_redable_sameLogicBt(vector<int> &days, vector<int> &costs, int index) {
  // Base case: If we are beyond the last travel day, no more cost is needed
  if (index >= days.size())
    return 0;

  int minCost = INT_MAX;
  int one_day_pass = days[index] + 1;
  int one_day_pass_cost = costs[0] +  mincostTicketsSir_compact_more_redable_sameLogicBt(days, costs, index + 1);

  int seven_day_pass = days[index] + 7;
  int nextIndex = index;
  while (days[nextIndex] < seven_day_pass) {
    nextIndex++;
  }
  int seven_day_pass_cost = costs[1] +  mincostTicketsSir_compact_more_redable_sameLogicBt(days, costs, nextIndex);

  int thirty_day_pass = days[index] + 30;
  nextIndex = index;
  while (days[nextIndex] < thirty_day_pass) {
    nextIndex++;
  }
  int thirty_day_pass_cost = costs[30] +  mincostTicketsSir_compact_more_redable_sameLogicBt(days, costs, nextIndex);

  return min(one_day_pass_cost,min(seven_day_pass_cost,thirty_day_pass_cost));
}

int main(int argc, char const *argv[]) {
  vector<int> day{1, 4, 6, 7, 8, 20}, cost{2, 7, 15};
  //   vector<int> day{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, cost{2, 7, 15};

  cout << mincostTicketsRe_ME_With_Chatgpt_Help_At_Last(day, cost, 0)<<endl;
  cout << mincostTicketsSir_compact_more_redable_sameLogicBt(day, cost, 0)<<endl;
  return 0;
}
