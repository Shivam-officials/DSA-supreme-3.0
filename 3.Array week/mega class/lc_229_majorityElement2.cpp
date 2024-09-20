

#include <iostream>
#include <vector>
using namespace std;


// lc 229 https://leetcode.com/problems/majority-element-ii/description/

vector<int> majorityElement(vector<int> &nums) {

  int majorityCandidate1 = nums[0], vote1 = 0, majorityCandidate2 = -111, vote2 = 0;
            
             // majorityCandidte2  is -1 bcz if all the elemensta are same till
             // end then majorityCandidate2 will never be initialised so instead
             // of using garbage value initialising here to check in candidate
             // validation time bcz sometime garbage  value is zero too and
             // array can contain zero which increase majorityCandidate2 votes
             // without realising that majorityCandidate does not exist

  for (auto itm : nums) {
    if (majorityCandidate1 == itm) {
      vote1++;
    } else if (majorityCandidate2 == itm) {
      vote2++;
    } else if (vote1 == 0)

    {
      vote1++;
      majorityCandidate1 = itm;
    } else if (vote2 == 0) {
      vote2++;
      majorityCandidate2 = itm;
    } else {
      vote1--;
      vote2--;
    }
  }

  vote1 = 0;
  vote2 = 0;

  // candidate validation
  for (auto i : nums) {
    if (i == majorityCandidate1)
      vote1++;
  }

  for (auto i : nums) {
    if (i == majorityCandidate2)
      vote2++;
  }

  // ans
  vector<int> ans;
  if (vote1 > nums.size() / 3)
    ans.push_back(majorityCandidate1);
  if (vote2 > nums.size() / 3)
    ans.push_back(majorityCandidate2);

  return ans;
}

int main() {
  vector<int> v{0, 0, 0};
  auto it = majorityElement(v);

  for (auto ls : it) {
    cout << ls << endl;
  }
  cout << "finishd";
  return 0;
}
