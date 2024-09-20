//
// Created by shivam on 06-07-2024.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


void showArray(const vector<int> a, const int length) {
    cout<<"printing the vector\n";
    // for (int i = 0; i < length; ++i) {
    //     cout<<a[i]<< " ";
    // }
    for (auto it: a) {
        cout<<it<<" ";
    }
}

void sortVector(vector<int> &b) {
    sort(b.begin(), b.end()-1);
}

int main() {
/**
     int n;
    cout<<"enter the size of an array";
    cin>>n;
    int *arr = new int[n];

    cout<<"enter the elements";
    for (int i = 0; i <= n; ++i) {
        cin>>arr[i];
    }


    cout<<"enter the more elements";
    for (int i = 5; i < n+5; ++i) {
        cin>>arr[i];
    }

    showArray(arr,n+5);
    showArray(arr,n);
    delete arr;

    */

   vector<int> v {2221,22,3} ;

    v.push_back(4);
    v.push_back(8);
//     v.push_back(12);
// for (int i = 0; i < v.size(); ++i) {
//     cout<<v.at(i)<<" ";
// }
//     cout<<"-----------\n";
//
//     while(v.size()>0){
//         v.pop_back();
//        showArray(v,v.size());
//
//        cout<<"--------"<<endl;
//     }
//     v.pop_back();
//     v.pop_back();
//     v.pop_back();
//
// for (int i = 0; i < 100; ++i) {
//      v.pop_back();
//     cout<<"popped "<<i<<" times\n";
// }
//
//     v.clear();
//     v.push_back(8);
//     showArray(v,v.size());
//     // v.
//     return 0;

    /**
    showArray(v,v.size());
    vector<int>b(v);
    b.push_back(77);
    showArray(b,b.size());
    cout<<b.front()<<" "<<*b.end();
    showArray(b,b.size());
    cout<<"\n-----------\n"<<b.capacity();
    sortVector(b);
    showArray(b,b.size());j
    */

    cout<< (5 ^ 5);
}
