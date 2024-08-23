#include <iostream>
#include <vector>

// took 20 minutes
//
// Algorithm overview:
// - find an index that has the target. It can be any valid index that matches.
//     If can't find, then return [-1, -1]
// - find the first and last index where the target occurs, using the "find"
//     index for the upper and lower bound respectively
// - Probably don't actually need the first search, thought it might make it
//     easier to code when brainstorming
//
// Runtime: O(logn)
// - binary search 3 times
//
// Additional space: O(1)
// - only need a few pointers
//

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
  int front = -1;
  int end = -1;
  int low, mid, high;
  int find = -1;

  low = 0;
  high = nums.size();
  while (low < high) {
    mid = (low + high) / 2;
    if (nums.at(mid) == target) {
      find = mid;
      break;
    } else if (nums.at(mid) < target) {
      low = mid + 1;
    } else if (nums.at(mid) > target) {
      high = mid;
    }
  }
  if (find == -1)
    return {-1, -1};

  if (nums.at(0) == target) {
    front = 0;
  } else {
    low = 0;
    high = find + 1;
    while (low < high) {
      mid = (low + high) / 2;
      if (mid > 0 && nums.at(mid - 1) == target) {
        high = mid;
      } else if (nums.at(mid) == target) {
        front = mid;
        break;
      } else {
        low = mid + 1;
      }
    }
  }

  if (nums.at(nums.size() - 1) == target) {
    end = nums.size() - 1;
  } else {
    low = find;
    high = nums.size();
    while (low < high) {
      mid = (low + high) / 2;
      if (mid < nums.size() - 1 && nums.at(mid + 1) == target) {
        low = mid + 1;
      } else if (nums.at(mid) == target) {
        end = mid;
        break;
      } else {
        high = mid;
      }
    }
  }

  return {front, end};
}

int main(void) {

  /*vector<int> query = {5, 7, 7, 8, 8, 10};*/
  vector<int> query = {1, 3};
  int target = 3;
  vector<int> out = searchRange(query, target);

  for (auto i : out) {
    cout << i << ' ';
  }
  cout << endl;
}
