#include <iostream>
#include <vector>
using namespace std;


int mySqrt(int x) {
        if (x == 0)
            return x;
        int first = 1, last = x,ans;
        while (first <= last) {
           int  mid = first + (last - first) / 2;
            if (mid  == x / mid)
                return mid;
            else if (mid > x / mid) {
                last = mid-1;
            }
            else {
                first = mid+1;
                ans = mid;
            }
        }
        // return ans;
        return last; // this will also work
    }

int main()
{
    cout << mySqrt(98);
    return 0;
}
