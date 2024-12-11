#include <iostream>
#include <vector>
using namespace std;

// https://www.naukri.com/code360/problems/print-series_1081471?redirectFromApp=true&userSignInOrSignupflag=true&leftPanelTabValue=PROBLEM

void print(vector<int> &ans, int n, int k, int num,bool flag) {
    // base case
    if(n > num ){
        return;
    }

    ans.push_back(n);
    
    if(n<=0){
        flag = true;
    }

    if(!flag)
        
        print(ans, n - k, k, num,flag); // Decrease n
    else
        print(ans, n + k, k, num,flag); // Increase n

}

vector<int> printSeries(int n, int k) {
    vector<int> ans;

    int num = n;
    // ans.push_back(n);
    bool flag = false;
    print(ans, n, k, num,flag);

  return ans;
}

int main(int argc, char const *argv[])
{
    auto ans = printSeries(3, 2);
    for (auto elm : ans)  {
    cout << elm<<" ";
    }
    return 0;
}
