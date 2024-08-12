#include <cmath>
#include <map>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> hash;

  while(n--){
    int val;
    cin >> val;
    hash[val]++;
  }

  // for (auto i: hash){
  //   cout << i.first << ", " << i.second << endl;
  // }

  int ret = 0;

  ret += hash[4];
  hash[4] = 0;

  ret += hash[3];
  int three_ones = min(hash[3], hash[1]);
  hash[1] -= three_ones;
  hash[3] = 0;

  // at this point, no 3's, no 4's, could be some 1's and some 2's
  
  ret += ceil(hash[2] / 2.0);
  int two_one_ones = min((hash[2] % 2) * 2, hash[1]);
  // cout << "211 one's: " << two_one_ones << endl;
  
  hash[2] = 0;
  hash[1] -= two_one_ones;

  ret += ceil(hash[1] / 4.0);
  hash[1] = 0;

  // for (auto i: hash){
  //   cout << i.first << ", " << i.second << endl;
  // }

  cout << ret << endl;

  return 0;
}
