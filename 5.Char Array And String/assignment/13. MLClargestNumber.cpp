#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;



/*
* @complexity: 
Time Complexity: O(n * d * log n)
- n: number of integers
- d: average number of digits in each integer
- Sorting dominates, where each comparison takes O(d) and we perform O(n log n) comparisons.

Space Complexity: O(n * d)
- O(n * d) for storing the strings and final concatenated result.
*/



// the below is faster bcz it does not use that much defualt stl functions
string largestNumber_OptimisedForReadablityAndCoding(vector<int> &nums)
{
    // Convert integers to strings
    vector<string> numString;
    
    // Reserve space to avoid multiple reallocations for efficiency
    numString.reserve(nums.size());

    // Convert each integer in the input vector 'nums' to a string and store it in 'numString'
    for (int num : nums)
    {
        numString.push_back(to_string(num));
    }

    // Sort the strings using a custom comparator that compares concatenated results
    // For example, for "9" and "34", compare "934" vs "349" and sort accordingly
    sort(numString.begin(), numString.end(), [](const string &a, const string &b) {
        return a + b > b + a;
    });

    // If the largest number after sorting is "0", that means all numbers were zero
    // Hence, return "0" to handle the edge case of all zeros
    if (numString[0] == "0")
        return "0";

    // Use the 'accumulate' function to concatenate all sorted strings into one large string
    // Start with an empty string as the initial value
    return accumulate(numString.begin(), numString.end(), string());
}

string largestNumber(vector<int> &nums)
{
    // Step 1: Convert each integer in the input vector to a string
    // This is done because we want to compare and concatenate them as strings
    vector<string> numString;

    for (auto elm : nums)
    {
        numString.push_back(to_string(elm));  // Convert each number to string
    }

    // Step 2: Sort the strings based on custom comparator
    // The key intuition here is to decide the order of two numbers by comparing
    // which concatenation (a + b or b + a) gives a larger value.
    sort(numString.begin(), numString.end(), [](string a, string b) -> bool
    {
        /**
          string t1 = a + b;  // Concatenate a followed by b
          string t2 = b + a;  // Concatenate b followed by a
          return t1 > t2;     // If a+b is greater than b+a, we keep 'a' before 'b'
         */
         return a+b>b+a;
       
    });

    // Step 3: Edge case handling - If the largest number is "0"
    // After sorting, if the largest number is "0", all numbers are "0".
    if (numString[0] == "0")
    {
        return "0";  // Return "0" because all elements are zeros
    }

    // Step 4: Concatenate all the strings in the sorted order
    // Join all strings in the vector to form the final largest number
    string str = "";
    for (auto elm : numString)
    {
        str += elm;  // Append each sorted string to the result
    }

    // Return the final concatenated result
    return str;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{3,30,34,5,9};
    // vector<int> nums{3,-30,-34,-5,9};
    // vector<int> nums{532,511,436};
    vector<string> numString ;

   
    cout <<  largestNumber(nums);


    return 0;
}
