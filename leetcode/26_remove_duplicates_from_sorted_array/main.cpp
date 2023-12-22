#include <iostream>
#include <set>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
  set<int> hash;
  int ret = 0;
  // for (int i = nums.size() - 1; i >= 0; i--) {
  for (int i = 0; i < nums.size(); i++) {
    // if duplicate
    cout << "Checking " << nums.at(i) << endl;
    if (hash.find(nums.at(i)) != hash.end()) {
      cout << "Found " << nums.at(i) << ". Adding to ret" << endl;
      nums.erase(nums.begin() + i);
      i--;
    }
    // if not duplicate
    else {
      cout << "Could not find " << nums.at(i) << ". Adding to the set" << endl;
      hash.insert(nums.at(i));
      ret++;
    }
  }
  return ret;
}

int main() {
  vector<int> a = {1, 1, 2};

  int ret = removeDuplicates(a);

  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
