#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

// Helper function to calculate the time taken to collect a specific garbage type
int timeTakenForCurrentGarbageType(vector<string>& garbage, vector<int>& travel, char currentGarbageType) {
    int timeTakenForGarbageCollection = 0;  // Stores total time taken for collecting this garbage type
    int distanceCovered = 0;                // Tracks total distance covered between houses
    int distanceCoveredForCurrentGarbageType = 0;  // Tracks last distance covered for the current garbage type

    // Iterate over each house's garbage
    for (int i = 0; i < garbage.size(); i++) {
        string houseGarbage = garbage[i];  // Garbage in the current house
        int currentHouseGarbageCollectionTime = 0;  // Time taken to collect current type in this house

        // Add travel distance between houses (skip for the first house)
        if (i > 0) {
            distanceCovered += travel[i - 1];
        }

        // Count how many pieces of the current garbage type are in this house
        for (auto garbageType : houseGarbage) {
            if (garbageType == currentGarbageType) {
                currentHouseGarbageCollectionTime++;
            }
        }

        // If the current garbage type is collected at this house, update the total time and distance
        if (currentHouseGarbageCollectionTime > 0) {
            timeTakenForGarbageCollection += currentHouseGarbageCollectionTime;
            distanceCoveredForCurrentGarbageType = distanceCovered;  // Store distance for this garbage type
        }
    }
    // Return total time: collection time + distance traveled for this type of garbage
    return distanceCoveredForCurrentGarbageType + timeTakenForGarbageCollection;
}

/**
 * @TC = O(n * m), where n is the number of houses, and m is the average length of the garbage string for each house.Since the number of
 * garbage types is constant (3), it doesn't affect the complexity.

 *SC = O(1)
*/
// Main function to calculate the total garbage collection time 
int garbageCollection_ME_BruteForce_lessOptimized(vector<string>& garbage, vector<int>& travel) {
    string garbageType = "MPG";  // The three types of garbage: Metal (M), Paper (P), Glass (G)
    int ans = 0;

    // Calculate the time for each garbage type (M, P, G) and add them up
    for (auto currentGarbageType : garbageType) {
        ans += timeTakenForCurrentGarbageType(garbage, travel, currentGarbageType);
    }
    return ans;  // Return the total time taken for garbage collection
}


// Optimized solution (iterative approach) 
// TC = O(n) SC = O(1)
int garbageCollection_Optimized_sir(vector<string>& garbage, vector<int>& travel) {
    // Initialize pickup times and last stops for P, M, G
    int pickTimeForP = 0, pickTimeForM = 0, pickTimeForG = 0;
    int lastStopForP = 0, lastStopForM = 0, lastStopForG = 0;

    // Calculate pickup times and last stop indices
    for (int i = 0; i < garbage.size(); i++) {
        string garbageInHouse = garbage[i];
        for (auto garbageType : garbageInHouse) {
            if (garbageType == 'M') {
                pickTimeForM++;
                lastStopForM = i;
            } else if (garbageType == 'G') {
                pickTimeForG++;
                lastStopForG = i;
            } else {
                pickTimeForP++;
                lastStopForP = i;
            }
        }
    }

    // Calculate travel time for each truck (P, M, G)
    int timeForTruckP = 0, timeForTruckM = 0, timeForTruckG = 0;
    for (int i = 0; i < lastStopForP; i++) timeForTruckP += travel[i];
    for (int i = 0; i < lastStopForM; i++) timeForTruckM += travel[i];
    for (int i = 0; i < lastStopForG; i++) timeForTruckG += travel[i];

    // Return total time for all trucks
    return timeForTruckG + timeForTruckM + timeForTruckP + pickTimeForG + pickTimeForM + pickTimeForP;
}

// Observationally optimized solution
int garbageCollection_optimized_ME_Observationaly(vector<string>& garbage, vector<int>& travel) {
    // Initialize last stop indices and travel times for P, M, G
    int lastStopForP = 0, lastStopForM = 0, lastStopForG = 0;
    int timeForTruckP = 0, timeForTruckM = 0, timeForTruckG = 0;
    int timeTakenForPickup = 0;

    // Calculate the pickup time and last stop indices
    for (int i = 0; i < garbage.size(); i++) {
        string currentHouseGarbage = garbage[i];
        timeTakenForPickup += currentHouseGarbage.length();
        if (currentHouseGarbage.find('P') != string::npos) lastStopForP = i;
        if (currentHouseGarbage.find('M') != string::npos) lastStopForM = i;
        if (currentHouseGarbage.find('G') != string::npos) lastStopForG = i;
    }

    // Calculate travel times for trucks
    for (int i = 0; i < lastStopForP; i++) timeForTruckP += travel[i];
    for (int i = 0; i < lastStopForM; i++) timeForTruckM += travel[i];
    for (int i = 0; i < lastStopForG; i++) timeForTruckG += travel[i];

    // Return total time (pickup + travel)
    return timeTakenForPickup + timeForTruckM + timeForTruckG + timeForTruckP;
}
int main()
{
   vector<string> garbageArray {"G","P","GP","GG"};
   vector<int>travelArray{2,4,3};
   string ds = "dkjfa";
    // cout << garbageCollection_ME_BruteForce_lessOptimized(garbageArray, travelArray);
    // cout << garbageCollection_Optimized_sir(garbageArray, travelArray);
    cout << garbageCollection_optimized_ME_Observationaly(garbageArray, travelArray);
   

    
    return 0;
}
