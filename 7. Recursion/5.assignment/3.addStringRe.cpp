#include <iostream>
#include <algorithm>
using namespace std;


// TC = O(max(n,m))  SC = O(max(n,m))
void addStringRecursion(string &str1, string &str2, int carry, int index, string &ans) {
    int l1 = str1.size() - 1;
    int l2 = str2.size() - 1;

    // Base case: stop if all digits processed and no carry
    if (l1 - index < 0 && l2 - index < 0 && carry <= 0) {
        return;
    }

    // Get current digits from str1 and str2, or 0 if out of bounds
    int temp1 = l1 - index >= 0 ? str1[l1 - index] - '0' : 0;
    int temp2 = l2 - index >= 0 ? str2[l2 - index] - '0' : 0;
    int digit = temp1 + temp2 + carry; // Sum of current digits and carry
    carry = digit / 10; // Update carry

    ans.push_back(digit % 10 + '0'); // Append last digit to result

    addStringRecursion(str1, str2, carry, index + 1, ans); // Recur for next digits
}

int main(int argc, char const *argv[]) {
    string st1 = "123", st2 = "45", ans = "";
    addStringRecursion(st1, st2, 0, 0, ans);
    reverse(ans.begin(), ans.end()); // Reverse result for correct order
    cout << ans;
    return 0;
}
