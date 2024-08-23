#include <map>
#include <vector>

using namespace std;
int removeDuplicates(vector<int> &nums) {
  map<int, int> hash;
  int ret = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (hash.find(nums.at(i)) == hash.end()) {
      // new item
      hash.insert(make_pair(nums.at(i), 1));
      ret++;
    } else if (hash.find(nums.at(i))->second == 2) {
      // old item but too many
      nums.erase(nums.begin() + i);
      i--;
    } else {
      // exactly 1
      hash.find(nums.at(i))->second += 1;
      ret++;
    }
  }
  return ret;
}
