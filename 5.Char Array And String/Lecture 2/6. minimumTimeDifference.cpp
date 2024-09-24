// https://leetcode.com/problems/minimum-time-difference/description/

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Converts a time in "HH:MM" format to total minutes since 00:00

int hourToMinutes(string &time) {
  int h1 = stoi(time.substr(0, time.find(":")));  // Extract hours
  int m1 = stoi(time.substr(time.find(":") + 1)); // Extract minutes
  return h1 * 60 + m1;                            // Convert to total minutes
}

// Calculates the absolute time difference between two times, adjusted for 24-hour wrap-around
int timeDifferenceBetweenTwoTimes(string time_1, string time_2) {
  int totalMin1 = hourToMinutes(time_1);
  int totalMin2 = hourToMinutes(time_2);
  int diff = abs(totalMin1 - totalMin2);
  return (diff > 720) ? (1440 - diff) : diff; // Adjust if difference exceeds 12 hours
}

// TC = O(n^2) 
// brute-force method to find minimum time difference between any two times
int findMinDifference_ME_NotOptimized(vector<string> &timePoints) {

  if (timePoints.size() < 2) return 0;

  int minDiff = INT_MAX;

  for (int i = 0; i < timePoints.size(); i++) {

    for (int j = i + 1; j < timePoints.size(); j++) {
      int diff = timeDifferenceBetweenTwoTimes(timePoints[i], timePoints[j]);
      minDiff = min(minDiff, diff);
    }

  }
  
  return minDiff;
}

// O(n log n)
// optimized solution: converts times to minutes, sorts, and checks consecutive differences
int findMinDifference(vector<string> &timePoints) {
  vector<int> minutes;

  // Convert all times to minutes and store in vector
  for (auto time : timePoints) {

    int timeInMinute = hourToMinutes(time);
    minutes.push_back(timeInMinute);

  }

  sort(minutes.begin(),  minutes.end()); // Sort times in ascending order, O(n log n)

  int minDiff = INT_MAX;

  // Find minimum difference between consecutive times

  for (int i = 0; i < minutes.size(); i++) {

    /** 
    * Wrap-around case: checks the difference between the first and last time
    * Example: First time = 00:30 (30 minutes), Last time = 23:45 (1425 minutes)
    * Diff = 1440 - 1425 + 30 = 45 (the difference between 23:45 and 00:30 is 45 minutes)
    */
    int diff = (i == 0) ? (1440 - minutes.back() + minutes[0]) : (minutes[i] - minutes[i - 1]);    /** Wrap-around case : Normal case */    

    minDiff = min(minDiff, diff);

  }

  return minDiff; // Return the minimum difference
}

int main() {
  string time_1 = "23:59";
  string time_2 = "00:59";
  vector<string> timePoints{"23:59", "00:00"};
  cout << findMinDifference(timePoints);
  return 0;
}
