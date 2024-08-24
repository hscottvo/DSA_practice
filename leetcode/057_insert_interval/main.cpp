#include <complex>
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  int start = newInterval.at(0);
  int end = newInterval.at(1);

  if (intervals.size() == 0) {
    return {newInterval};
  } else if (newInterval.at(0) > intervals.at(intervals.size() - 1).at(1)) {
    auto ret = intervals;
    ret.push_back(newInterval);
    return ret;
  } else if (newInterval.at(1) < intervals.at(0).at(0)) {
    vector<vector<int>> ret = {newInterval};
    for (auto j : intervals) {
      ret.push_back(j);
    }
    return ret;
  }

  int i;

  // get the first index that merges w the new interval
  for (i = 0; i < intervals.size(); i++) {
    if (intervals.at(i).at(1) > newInterval.at(0)) {

      break;
    }
  }

  vector<vector<int>> ret;
  int idx;

  for (idx = 0; idx < i; idx++) {
    ret.push_back(intervals.at(idx));
  }
  if (i == intervals.size()) {
    return {
        {intervals.at(0).at(0), max(intervals.at(0).at(1), newInterval.at(1))}};
  }

  int start_new_int = min(intervals.at(idx).at(0), newInterval.at(0));
  int end_new_int = newInterval.at(1);
  cout << "New: " << start_new_int << endl;
  for (; idx < intervals.size(); idx++) {

    if (intervals.at(idx).at(0) > newInterval.at(1)) {
      /*ret.push_back({start_new_int, end_new_int});*/
      break;
    } else {
      end_new_int = max(end_new_int, intervals.at(idx).at(1));
    }
  }
  if (intervals.at(idx - 1).at(0) <= newInterval.at(1)) {
    ret.push_back({start_new_int, end_new_int});
  }

  for (; idx < intervals.size(); idx++) {
    ret.push_back(intervals.at(idx));
  }

  return ret;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> new_interval = {3, 6};
  auto x = insert(intervals, new_interval);
  for (auto i : x) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
