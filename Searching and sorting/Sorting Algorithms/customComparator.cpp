#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;

void printVector(vector<int> v){
    for (auto elmt : v) {
     cout << elmt << endl;
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

bool mycomp(int &a, int &b){
    
    return  a>b; // descending order

    // return a<b; //increasing order
}


bool myCompFor1stIndex(const vector<int> &a, const vector<int>&b){

    return a[1]<b[1];
}

int main()
{
    vector<int> v = {5,4,6,3,2,1};

    vector<vector<int>> matrix ;
    int n;
    cout<<"enter the size";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
           int a,b;
            cout<<"enter first and 2nd value" <<endl;
            cin >>a>>b;
            matrix.push_back({a,b});
        
    }
    sort(matrix.begin(),matrix.end(),myCompFor1stIndex);
    showVectorMatrix(matrix);    


    return 0;
}