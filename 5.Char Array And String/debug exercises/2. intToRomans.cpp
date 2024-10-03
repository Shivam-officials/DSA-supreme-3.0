#include <iostream>
using namespace std;

// Integer to Romans. 1 ≤ n ≤ 3999.

string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM","MMM"};
        
        // return ths[num/1000] + hrns[(num%1000)%100] + tens[(num%100)%10] + ones[num%10];
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
}

int main(int argc, char const *argv[])
{
    cout << intToRoman(3949);
    return 0;
}

