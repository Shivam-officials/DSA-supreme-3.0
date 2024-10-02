#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
using namespace std;

// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

// TC = O(n * m) n = size of vector , m = length of each row
int numberOfBeams(vector<string> &bank) {

  // Variable to store the total number of beams between the security devices.
  int totalBeams = 0;

  // This keeps track of the number of security devices in the previous row that had devices.
  int numberOfSecurityDevicesInLastRow = 0;
  
  // Loop through each row of the 'bank'.
  for (int rowIndex = 0; rowIndex < bank.size(); rowIndex++) {

    // Get the current row as a string (either "001", "110", etc.).
    string currentRow = bank[rowIndex];

    // Variable to count the number of '1's (security devices) in the current row.
    int currentSecurityDeviceNumbers = 0;

    // Traverse each cell in the current row.
    for (auto cell : currentRow) {
      // If the cell contains a '1', it means there's a security device.
      if (cell == '1') {
        currentSecurityDeviceNumbers++;
      }
    }

    // If the current row contains at least one security device:
    if (currentSecurityDeviceNumbers > 0) {
      
      // If this is not the first row, add beams between the current row and the previous row that contained devices.
      if (rowIndex > 0) {
        // Multiply the number of devices in the current row with the number of devices in the last row.
        // This gives the total beams between the two rows.
        totalBeams += currentSecurityDeviceNumbers * numberOfSecurityDevicesInLastRow;
      }
      
      // Update the number of devices in the last row to be the current row's number of devices.
      numberOfSecurityDevicesInLastRow = currentSecurityDeviceNumbers;
    }
  }

  // Return the total number of beams formed.
  return totalBeams;
}


int main() {
  vector<string> bankSecurityAddress{"011001", "000000", "010100", "001000"};

  cout << numberOfBeams(bankSecurityAddress)<<endl ;


  return 0;
}
