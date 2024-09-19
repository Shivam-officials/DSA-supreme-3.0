#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/description/

bool isPossbleToEat(vector<int> piles, int hours, int assumedSpeed) {
    // Initialize a variable to keep track of the total time taken to finish all piles.
    int timeTakenToFinishPile = 0;
    
    // Loop through each pile and calculate the time required to finish it at the assumed speed.
    // We are dividing the pile size by assumedSpeed, rounding up using 'ceil', and adding to the total time.
    for (auto pile : piles) {
        timeTakenToFinishPile += ceil((pile / (double)assumedSpeed));
    }

    // Check if the total time required to eat all piles is less than or equal to the available hours.
    return timeTakenToFinishPile <= hours;
}

int minimumBananaEatingSpeed(vector<int> pile, int hour) {
    // Start of the binary search. Speed cannot be less than 1, so we initialize 'start' to 1.
    int start = 1;

    // The maximum eating speed cannot exceed the size of the largest pile.
    int end = *max_element(pile.begin(), pile.end());
    
    // Variable to store the result (minimum speed that allows finishing all piles within given hours).
    int mid;
    int ans = 0;

    // Perform binary search.
    while (start <= end) {
        // Calculate the mid-point (assumed speed) using bitwise shift for efficiency.
        mid = (start + end) >> 1;
        cout << "mid is -> " << mid << endl;

        // Check if it is possible to finish all the piles at this 'mid' speed within 'hour'.
        if (isPossbleToEat(pile, hour, mid)) {
            // If possible, update the answer and search for a potentially smaller speed by reducing 'end'.
            ans = mid;
            end = mid - 1;
        } else {
            // If not possible, increase the speed by adjusting 'start'.
            start = mid + 1;
        }
    }

    // Return the minimum eating speed that allows Koko to finish eating all bananas within the available hours.
    return ans;
}






int main()
{
    // vector<int>pile{ 30,11,23,4,20 };
    // vector<int>pile{ 3,6,7,11 };
    vector<int>pile{ 312884470 };
    cout << minimumBananaEatingSpeed(pile, 968709470);
    
    return 0;
}
