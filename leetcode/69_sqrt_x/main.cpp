#include <iostream>
using namespace std;
int mySqrt(int x) {
  if (x == 0) {
    return 0;
  }
  if (x == 1) {
    return 1;
  }

  long long lower = 0;
  long long middle = x / 2;
  long long upper = x;

  while (true) {
    // perfect square
    if (middle * middle == x) {
      return middle;
      // too high
    } else if (middle * middle > x) {
      upper = middle;
      middle = (lower + upper) / 2;
      // too low
    } else {
      if ((middle + 1) * (middle + 1) > x) {
        return middle;
      } else {
        lower = middle;
        middle = (lower + upper) / 2;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int val;
  cin >> val;

  cout << "input: " << val << endl;
  cout << "closest sqrt: " << mySqrt(val) << endl;
  return 0;
}
