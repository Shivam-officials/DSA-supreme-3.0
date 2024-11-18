#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/house-robber/


int HouseRobberRecursionSol(vector<int>nums,int index){

        //base case
        if(index >= nums.size())return 0;

        //include ka 1 case
        int include = nums[index]+HouseRobberRecursionSol(nums,index+2);
        //exclude ka 1 case
        int exclude = 0 + HouseRobberRecursionSol(nums,index+1);

        // return maximum among them
        cout <<index <<" "<< include<<" "<<exclude<<endl;
        return max(include,exclude);
}

int main(int argc, char const *argv[])
{
    // vector<int>house{2,7,9,3,1};
    vector<int>house{2,1,1,2};
    cout << HouseRobberRecursionSol(house, 0);
    return 0;
}
