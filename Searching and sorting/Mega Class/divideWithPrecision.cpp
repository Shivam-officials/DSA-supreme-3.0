#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double divideWithPrecision_BinarySearch(int dividend, int divisor,
                                        int precision) {
  int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

  double differ = 1 / pow(10, precision);
  int absDivident = abs(dividend);
  int absDivisor = abs(divisor);
  double start = 0;
  double end = (double)absDivident;
  double mid;
  double ans;
  while (end - start >= differ) {
    mid = (start + end) / 2;

    if (mid * divisor <= dividend) {
      ans = mid;
      start = mid;
    } else {
      end = mid;
    }
  }
  cout << "ans is the fucking" << ans << endl;
  return ans * sign;
}

double divide(int dividend, int divisor, int precision) {
  int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

  int absDivident = abs(dividend);
  int absDivisor = abs(divisor);
  int baseAns  = absDivident /absDivisor; // simulate here the simple binary search for int value ans
  // int end = absDivident;
  double start = baseAns;
  int mid;
  int ans = 0;

  double step = 0.1;
  while (precision--) {
    double j = start + step;
    while (j * absDivisor <= absDivident) {
      start = j;
      j += step;
      cout << "start is now " << start << endl;
    }
    step /= 10;
  }

  return start * sign;
}

int main() {
  int dividend = 68;
  int divisor = 7;
  int precision = 8;
  cout << fixed << setprecision(precision);

//   cout << divide(dividend, divisor, precision) << endl;
  cout << divideWithPrecision_BinarySearch(68, 7, precision);

  return 0;
}
