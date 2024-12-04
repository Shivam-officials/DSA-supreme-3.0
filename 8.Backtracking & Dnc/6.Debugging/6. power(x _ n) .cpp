#include <iostream>
using namespace std;

int power(int x, int n){
    if(n == 0) return 1;
    if(x == 0) return 0;
    int temp = power(x, n/2);
    // if(n % 2){
    if(n % 2 == 0){
        return temp*temp;
    } else{
        return temp*temp*x;
    }
}

int main() {
    cout << "2^5 = " << power(2, 5) << endl;  // Output: 32
    cout << "3^4 = " << power(3, 4) << endl;  // Output: 81
    cout << "5^0 = " << power(5, 0) << endl;  // Output: 1
    cout << "0^3 = " << power(0, 3) << endl;  // Output: 0
    return 0;
}
