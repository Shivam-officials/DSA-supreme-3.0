#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    // Track the current number and initialize pointer p for tracking the next position
    int currentNum = nums[0]; // Start with the first number
    int p = 0; // Position tracking where the next valid element will be placed
    int count = 0; // Count occurrences of the current number

    // Iterate through the array
    for (int i = 0; i < nums.size();) {
        // Visit each integer and count its occurrences
        while (i < nums.size() && currentNum == nums[i]) {
            count++; // Count this occurrence
            // If occurrence is less than or equal to 2, place it at position p
            if (count <= 2) {
                nums[p++] = nums[i]; // Place the valid number at position p and increment p
            }
            i++; // Move to the next number
        }

        // If we've reached the end of the array, exit the loop
        if (i == nums.size()) break;

        // Store the next different number at position p
        nums[p++] = nums[i]; // Place the next unique number at position p
        currentNum = nums[i++]; // Update current number for counting its occurrences
        count = 1; // Reset count for the new number
    }
    
    return p; // Return the count of valid elements (at most two duplicates)
}

/** 
 *@note remember to use map if u have to deal with the occurances of something
*/

int removeDuplicates_withHashMap_easyImplementation(vector<int>& nums) {
     unordered_map<int,int>mp;
     int index = 0;
     for(auto ch:nums){
        if(mp.find(ch)==mp.end()){
            nums[index++] = ch;
            mp[ch]++;
        }else{
            if(mp[ch]==1){
                mp[ch]++;
                nums[index++]=ch;
            }
        }
     }
     return index;
}

int main(int argc, char const *argv[])
{
    vector<int> num {0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(num)<<endl;
    cout << removeDuplicates_withHashMap_easyImplementation(num);
    return 0;
}
