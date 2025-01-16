 #include <iostream>
 using namespace std;
 #include <vector>
 #include <algorithm>
 
  //Function to count the number of dominant pairs.
int dominantPairs(int n,vector<int> &arr){
    
    //Sorting the first half and second half of the array separately so that 
    sort(arr.begin(),arr.begin()+(n/2));//i remain in first half and j in second half
    sort(arr.begin()+(n/2),arr.end());
    
    //Initializing the answer.
    int ans=0;

    //Initializing the right pointer to the middle of the array.
    int right=n/2;
    
    //Loop to iterate through the left pointer.
    for(int left=0;left<n/2;left++){
        
        //Loop to iterate through the right pointer.
        while(right<n && arr[left]>=5*arr[right]){
            right++;
        }
        
        //Updating the answer by adding the count of dominant pairs.
        ans+=right-n/2; // this relation gives nmber of pairs & this works bcz right se choti value pe pair bnna possible hai to next left jo ki usse badi hogi usse pe to vo values se pair automatically possible hoga isiliye hm current right se check krenge ki ye yha se possible hai ya ni agr possible hai to isko bhi include kro ni jha tak ho ske
    }
    
    //Returning the final answer.
    return ans;
}  


    int main(int argc, char const *argv[])
    {
        vector<int>v{9,8,6,9,3,1,2,1,4};
        // vector<int>v{10,2,2,1};
        cout << dominantPairs(v.size(), v);
        return 0;
    }
    