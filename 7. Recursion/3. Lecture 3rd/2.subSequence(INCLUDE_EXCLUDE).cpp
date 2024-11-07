#include <iostream>
#include <vector>
using namespace std;



void findAllSubsequence(string inputString, string outputString,  int index,vector<string>&ans) {

  // base case ... rukna kab hai
  if (index == inputString.length()) {
    // cout << outputString << endl;
    ans.push_back(outputString);
    return;
  }

  // processing and recursion togethor 
  //include krdo
  findAllSubsequence(inputString, outputString + inputString[index],  index + 1,ans);
  
  // exclude krdo
  findAllSubsequence(inputString, outputString,  index + 1,ans);

}

int main(int argc, char const *argv[]) {
  string input = "1231", output = "";

  vector<string>ans ;

  findAllSubsequence(input, output, 0,ans);

  for (auto ch : ans) {
    cout << ch<<endl;
  }

  return 0;
}
