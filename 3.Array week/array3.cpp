//
// Created by shivam on 07-07-2024.
//
#include <iostream>
#include <vector>
using namespace std;


    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0; i< nums.size(); i++){
            for(int j = i+1; j< nums.size();j++){
                for(int k = j+1; k < nums.size(); k++){
                    if( (nums[i]+nums[j]+nums[k] == 0)){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);

                        ans.push_back(temp);

                    }
                }
            }
        }
        return ans;
    }


void showMatrix(int v[][4],int rows,int cols) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void showVectorMatrix(vector<vector<int>> v) {
    int rows = v.size();
    int cols = v[0].size();
    cout<<endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
}

void sumOfColOfMatrix(std::vector<std::vector<int>> & v) {
    for (int col = 0; col < v[0].size(); ++col) {
        int sum = 0;
        for (int row = 0; row < v.size(); ++row) {
            sum += v[col][row];
        }
        cout<<"the sum of "<<col<<"st row is "<<sum<<endl;
    }

}

int rightDiogonalSum(std::vector<std::vector<int>> b2) {
        int sum = 0;
    for (int row = 0; row < b2.size(); ++row) {

        for (int col = 0; col < b2[0].size(); ++col) {
            if (col == b2[0].size() - row -1) {
                sum += b2[row][col];
            }
        }
    }
        return sum;
    }

void transposeVector(std::vector<std::vector<int>> &v) {
        int rows = v.size();
        int cols = v[0].size();
        vector< vector<int> > ans(cols,vector<int>(rows));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0 ; col < cols; ++col) {
                ans[col][row] = v[row][col];
            }
        }

        showVectorMatrix(ans);


    }

int main() {
    int n;


    // vector<int> temp = {2,4,5,6,5};
    // matrix.push_back(temp);
    // matrix.push_back({4,5,6,7,9});
    // int rows = matrix.size(),cols = matrix.at(0).size();
    // showMatrix(matrix);
    int x[4] = {4,5,6,7};

        // {-1,0,1,2,-1,-4 };
    int b1 [4][4]=     {
        {10,20,30,5},
        {40,50,60,5},
        {70,80,90,5},
        {70,80,90,5},
    };
    vector<vector<int>> b2(4,vector<int>(4,10));




/** // vector and array matrix
    int valueS = 666;
        //for vector 2d array
    for (int row = 0; row < 4; ++row) {
        fill(b2[row].begin(),b2[row].end(),valueS++);
    }
        //for simple 2d arrayy
        for (int row = 0; row < 4; ++row) {
        fill(begin(b1[row]),end(b1[row]),valueS++);
    }

    showMatrix(b1,4,4);
    showVectorMatrix(b2);

    // cout<<"the size of arr 2d array "<<size(ar);

    */

      /**  //vector transpose

        vector<vector<int>> matrix =  {
            {10,30,5},
            {50,60,5},
            {80,90,5},
        };

        transposeVector(matrix);
*/


}

