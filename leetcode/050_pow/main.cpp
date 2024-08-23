// took 20 minutes
#include <iostream>

using namespace std;

double myPow(double x, int n) {
  bool is_neg = n < 0;
  long long m = n;

  // edge cases: 1 or -1
  if (m == 1) {
    return x;
  } else if (m == -1) {
    return 1 / x;
  }

  // force power to be positive for now
  if (is_neg) {
    m *= -1;
  }

  double ret = 1;
  while (m > 1) {
    long long power = 1;
    while (power <= m)
      power *= 2;
    power /= 2;
    double mult = x;
    m -= power;
    while (power /= 2) {
      mult *= mult;
    }
    ret *= mult;
  }

  // if it was an odd power
  if (m == 1) {
    ret *= x;
  }

  // if it was a negative power, then invert it
  if (is_neg) {
    ret = 1 / ret;
  }

  return ret;
}

int main(int argc, char *argv[]) {

  cout << myPow(2, -3) << endl;

  return 0;
}
