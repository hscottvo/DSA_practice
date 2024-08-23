#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int width = matrix.at(0).size();
  int height = matrix.size();

  // edge cases
  if (matrix.at(0).at(0) > target) {
    return false;
  }
  if (matrix.at(height - 1).at(width - 1) < target) {
    return false;
  }

  int low = 0;
  int mid;
  int high = matrix.size();

  while (true) {
    mid = (low + high) / 2;
    if (matrix.at(mid).at(0) <= target) {
      // if last row, or it has to be in this row
      if (mid == height - 1 || target < matrix.at(mid + 1).at(0)) {
        break;
      } else {
        low = mid;
      }
    }
    // too high value guess
    else if (matrix.at(mid).at(0) > target) {
      high = mid;
    }
  }

  vector<int> *row_vec = &matrix.at(mid);
  low = 0;
  high = width;

  while (low != high) {
    mid = (low + high) / 2;
    int val = row_vec->at(mid);
    cout << "val: " << val << endl;
    if (val == target) {
      return true;
    } else if (val < target) {
      low = mid + 1;
    } else if (val > target) {
      high = mid;
    }
  }

  return false;
}
int main(void) {
  vector<vector<int>> input = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  /*{1, 3}};*/

  for (auto i : input) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }

  bool x;
  int find = 30;
  x = searchMatrix(input, find);
  cout << "searching for " << find << ": ";
  if (x) {
    cout << "True!" << endl;
  } else {
    cout << "False!" << endl;
  }

  return 0;
}
