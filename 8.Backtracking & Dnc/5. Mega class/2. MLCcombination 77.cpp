#include <iostream>
#include <vector>
using namespace std;


void combinations_solve(int n ,int index, int k ,vector<int>&currentV, vector<vector<int>> &ans){
    //base case
    if(currentV.size() == k )
    {
        ans.push_back(currentV);
        return;
    }
    if(index >n)
    {
        return;
    }
    
    
        currentV.push_back(index);
        combinations_solve(n, index+1, k, currentV, ans);
        currentV.pop_back();
        combinations_solve(n, index+1, k, currentV, ans);    
    
}

vector<vector<int>> combinations(int n , int k){
    vector<vector<int>> ans;
    vector<int> currentV;
    
    combinations_solve(n,1,k,currentV,ans);
    
    return ans;
}

int main()
{
    int n = 4 , k =2;

    auto ans = combinations(n,k);
    for (auto batch : ans) {
        for (auto elm  : batch) {
            cout << elm <<" ";
        }
        cout << endl;
    }
    
    return 0;
}
