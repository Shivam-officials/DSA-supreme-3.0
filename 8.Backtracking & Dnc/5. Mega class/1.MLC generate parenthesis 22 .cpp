#include <iostream>
#include <vector>
using namespace std;

// Helper function to generate all valid combinations of parentheses
/**   Parameters:
  - ans: vector to store the valid combinations
  - n: total pairs of parentheses
  - openingParenthesis: current count of opening parentheses
  - closingParenthesis: current count of closing parentheses
  - outputString: current state of the string being built
*/
void generateParenthesis_Shivam(vector<string> & ans, int n, int openingParenthesis, int closingParenthesis, string outputString) {
    // Stop recursion if closing parentheses exceed opening or limits are breached
    if (closingParenthesis > openingParenthesis) return;
    if (closingParenthesis > n || openingParenthesis > n) return;

    // Add completed valid combination to the result
    if (openingParenthesis == n && closingParenthesis == n) {
        ans.push_back(outputString);
        return;
    }

    // Recurse by adding an opening parenthesis
    generateParenthesis_Shivam(ans, n, openingParenthesis + 1, closingParenthesis, outputString + "(");

    // Recurse by adding a closing parenthesis
    generateParenthesis_Shivam(ans, n, openingParenthesis, closingParenthesis + 1, outputString + ")");

    return;
}

// Main function to initiate the recursive process
// Returns a vector of all valid combinations of n pairs of parentheses
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generateParenthesis_Shivam(ans, n, 1, 0, "("); // Start with one opening parenthesis
    return ans;
}


int main()
{
    int n = 3;


    auto ans = generateParenthesis(n);
    for (auto str : ans) {
        cout << str<<endl;
    }
    
    return 0;
}
