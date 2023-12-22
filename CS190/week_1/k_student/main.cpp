#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int k;
  int curr;
  vector<int> vec;
  cin >> n;

  while (n--) {
    cin >> curr;
    vec.push_back(curr);
  }
  cin >> k;
  sort(vec.begin(), vec.end());

  unsigned int size = vec.size();
  while (k--) {
    cin >> curr;
    cout << vec.at(size - curr) << endl;
  }

  return 0;
}
