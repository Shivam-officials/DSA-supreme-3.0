#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


 int majorityElementByHashmap(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto v: nums){
            ++hash[v];
        }

        int n = nums.size();
        int ans;
        for(auto pair: hash){
            if(pair.second>n/2){
                ans = pair.first;
            }
        }

        return ans;
 }


//iterator to all the all array and if the vote is zero then make the current element the new majorityCandidate and vote to 1 otherwise check  if current element is  same as the majorityCandidate increase the vote otherwise decrease the vote  ;

 int majorityElementByMooreVootingAlgo(vector<int>v){
    int vote = 0;
    int majorityCandidate = v[0] ; // safe to make the first element the majorityCandidate alothougu it will be automatically set in the first iteration bcz of zero votes

    for (auto item : v)  {
        if (majorityCandidate == item) {
            vote++;
        }else if(vote == 0)
        {
            vote++;
            majorityCandidate = item;
        }else 
        {
            vote--;
        }
        
    }
 // Phase 2: Verify that the candidate is indeed the majorityCandidate element
    vote = 0;
    for (int num : v) {
        if (num == majorityCandidate) {
            vote++;
        }
    }

    // If the count of the candidate is greater than n/2, return it; otherwise return -1
    if (vote > v.size() / 2) {
        return majorityCandidate;
    } else {
        return -1;  // No majorityCandidate element found
    }

 }

int main()
{
    // vector<int>v{2,2,1,1,1,2,2};
    vector<int>v{3,2,3};
    cout<<majorityElementByMooreVootingAlgo(v);
    return 0;
}
