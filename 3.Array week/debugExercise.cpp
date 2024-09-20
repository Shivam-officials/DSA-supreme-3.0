//
// Created by shivam on 09-07-2024.
//

#include <iostream>
#include <tuple>
using namespace std;

int linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}


int pairSumToX(int input[], int size, int x){
    int pairs = 0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(input[i] + input[j] == x) pairs++;
        }
    }
    return pairs;
}

void sort0sand1s(int input[], int size){
    int nextZero = 0;
    for(int i=0; i<size; i++){
        if(input[i] == 0){
            std::swap(input[i],input[nextZero++]);
        }
    }
}


void populate(int arr[],int n){
    int j=0;
    // for(int i=0; i < n/2; i++){
    //     arr[i] = 2*i + 1;
    // }
    // int it = n;
    // for (int i = n/2; i < n; ++i) {
    //     arr[i] = it ;
    //     it = it -2;
    // }

    for(int i=0;i<n;i = i + 2){
        arr[n-j-1] = i+2;
        arr[j] = i+1;
        j++;
    }
}

/** sum of an array
 #include<iostream>
 using namespace std;
 int main(){
    int n, sum = 0;
    cin >> n;
    int input[n];
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    for(int i=0; i<n; i++){
        sum = sum + input[i];
    }
    cout << sum << endl;
    return 0;
}

*/

using namespace std;
int main(int argc, char *argv[]) {
    int ar[10] = {0};
    populate(ar,10);
    for (int i = 0; i < 10; ++i) {
        cout<<ar[i]<<" ";
    }
}


