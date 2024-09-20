//
// Created by shivam on 06-07-2024.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void showArray(int a[], const int length) {
    for (int i = 0; i < length; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void HWfindUniqueNmberInArrayWithoutXOR(const int n[], const int size_of_array) {
    int uniqueNumber = -1;

    for (int i = 0; i < size_of_array; ++i) {
        bool isMatched = false;
        for (int j = 0; j < size_of_array; ++j) {
            if (i == j) {
                continue;
            }

            if (n[i] == n[j]) {
                isMatched = true;
                break;
            }
        }

        if (!isMatched) {
            uniqueNumber = n[i];
        }
    }

    cout << "the unique nmber is " << uniqueNumber;
}

void sort0_s_and1_s(vector<int> &v, int size_of_array) {
    int countOfZero = 0;
    for (auto it: v) {
        if (it == 0) {
            countOfZero++;
        }
    }
    // for (int i = 0; i < size_of_array; ++i) {
    //     if (i<= countOfZero -1) {
    //         v.at(i) = 0;
    //     }else {
    //         v.at(i) = 1;
    //     }
    // }
    fill(v.begin(), v.begin() + countOfZero, 0);
    fill(v.begin() + countOfZero, v.end(), 1);
}

void sort0_s_and1_s_and2_s(std::vector<int> &v, int size_of_array) {
    int countOfZero = 0;
    int countOf1s = 0;
    for (auto it: v) {
        if (it == 0) {
            countOfZero++;
        } else if (it == 1) {
            countOf1s++;
        }
    }
    for (int i = 0; i < size_of_array; ++i) {
        if (i <= countOfZero - 1) {
            v.at(i) = 0;
        } else if (i < countOfZero + countOf1s) {
            v.at(i) = 1;
        } else {
            v.at(i) = 2;
        }
    }
}

void printPairs(std::vector<int> &v, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0 ; j<size ; ++j) {
            cout << " <" << v.at(i) << "," << v.at(j) << "> ";
        }
        cout << endl;
    }
}

pair<int,int> twoSum(const std::vector<int> & v, int size,int sum) {
    pair<int,int> ans = make_pair(-1,-1);
    int sumCount = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0 ; j < size; ++j) {
            if ((i != j)  && v.at(i) + v.at(j) == sum) {
                ans = make_pair(v.at(i),v.at(j));
                return ans;
            }
        }
    }
    return ans;
}

void printTriplets(std::vector<int> & v, int size, int target) {
    int ans[3];
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                if (i!= j && j!= k && i!=k  && v.at(i)+v.at(j)+v.at(k) == target) {
                    cout<<" ("<<v.at(i)<<","<<v.at(j)<<","<<v.at(k)<<") "<<endl;
                    count++;
                }
            }
        }
        cout<<"*******************"<<endl;
    }
cout<< "the count is "<<count<<endl;
}

void rotateArray(std::vector<int> & v, int shift) {
    //my way
    /**
     * // my way and it space complexity is very bad as it will create the array of same size so its o(n)
    int sizeOfArray = v.size();
    vector<int> ans(sizeOfArray,0);

    for (int i = 0; i < sizeOfArray; ++i) {
        int swapPosition = (i+position)%(sizeOfArray );
        // swap(v.at(i),v.at(swapPosition));
        ans.at(swapPosition) = v.at(i);
        INT_MIN;
    }
    cout<<"\nthe rotated array is \n";
    showArray(ans.data(),ans.size());
    cout<<endl;
    */

    // sir way

    int sizeOfArray = v.size();
    vector<int>temp;

    //populating the temp array
    for (int i = sizeOfArray - shift; i < sizeOfArray; ++i) {
        temp.push_back(v.at(i));
    }

    // shifting elements forward
    for (int i = sizeOfArray-1; i >= shift; ++i) {
        int finalShift = shift % sizeOfArray;
        v.at(i) = v.at(i-finalShift);
    }

    //coping temp array to original array array
    for (int i = 0; i < shift; ++i) {
        v.at(i) = temp.at(i);
    }

    showArray(v.data(),v.size());

}

int main(int argc, char *argv[]) {
    // vector<int>v = {1,2,0,1,0};
    // vector<int>v = {1,1,0,0,1,0,0,0,1};
    // vector<int>v = {1,1,2,3,2,5,3,5,4};

    vector<int> v = {10, 20, 30, 40, 50};
    // vector<int> v = {10,5, 15, 20, 30, 0};


    int sizeOfArray = v.size();
    // HWfindUniqueNmberInArrayWithoutXOR(v.data(),sizeOfArray);
    showArray(v.data(), v.size());

    // sort0_s_and1_s(v, sizeOfArray);

    // sort0_s_and1_s_and2_s(v, sizeOfArray);


    // sort(v.begin(), v.end());

    int target = 3;
    // pair<int,int> found_pair =  twoSum(v,v.size(),target);
    //
    //
    // if (found_pair.first == -1) {
    //     cout<<"pair dont found\n";
    // } else {
    //     cout<<"the pair is the ("<< found_pair.first<<","<<found_pair.second<<") ";
    // }

    //printing triplets
    // printTriplets(v,v.size(),target);


    cout<<"printing the pairs";
    printPairs(v, v.size());

    int position = 2;
    // rotateArray(v,position);
    // showArray(v.data(), v.size());

}
