#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//TC = O(2^N) SC = O(N)  

 int HouseRobberSolve2(vector<int> &nums, int index, int size) {
    // Base case: If index is out of bounds
    if (index >= size) return 0;

    // Include current house, skip next
    int include = nums[index] + HouseRobberSolve2(nums, index + 2, size);

    // Exclude current house, move to next
    int exclude = HouseRobberSolve2(nums, index + 1, size);

    // Return max of including or excluding current house
    return max(include, exclude);
}


int rob(vector<int> &houses) {
    int n = houses.size();
    // Handle edge cases for no houses or single house
    if (n == 0) return 0;
    if (n == 1) return houses[0];

    // Case 1: Rob houses from index 0 to n-2
    int option1 = HouseRobberSolve2(houses, 0, n - 1);

    // Case 2: Rob houses from index 1 to n-1
    int option2 = HouseRobberSolve2(houses, 1, n);

    // Return max of both cases
    return max(option1, option2);
}



int main()
{
    // vector<int>v{ 1,2,3,1  };
    vector<int>v{2,3,2  };
    cout << rob(v);
    
    return 0;
}
