#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  /*empty input*/
  vector<vector<int>> ret;
  if (intervals.size() == 0)
    return {newInterval};
  /*interval is left of input*/
  if (intervals.at(0).at(0) > newInterval.at(1)) {
    ret.push_back(newInterval);
    for (auto i : intervals)
      ret.push_back(i);
    return ret;
  }
  /*interval is right of input*/
  if (intervals.at(intervals.size() - 1).at(1) < newInterval.at(0)) {
    for (auto i : intervals)
      ret.push_back(i);
    ret.push_back(newInterval);
    return ret;
  }

  int start;
  // add anything that doesn't need to be merged, on the left side of the
  // interval
  for (start = 0; start < intervals.size(); start++) {
    // if the current interval can be merged, break. otherwise just push
    if (intervals.at(start).at(1) >= newInterval.at(0)) {
      break;
    }
    ret.push_back(intervals.at(start));
  }

  int new_start = min(newInterval.at(0), intervals.at(start).at(0));
  int new_end;
  if (newInterval.at(1) >= intervals.at(start).at(0)) {
    new_end = max(newInterval.at(1), intervals.at(start).at(1));
  } else {
    new_end = newInterval.at(1);
  }
  for (; start < intervals.size(); start++) {
    if (intervals.at(start).at(0) > newInterval.at(1)) {
      break;
    }
    new_end = max(new_end, intervals.at(start).at(1));
  }

  ret.push_back({new_start, new_end});

  for (; start < intervals.size(); start++) {
    ret.push_back(intervals.at(start));
  }

  return ret;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> intervals = {{3, 5}, {12, 15}};
  vector<int> new_interval = {6, 6};
  auto x = insert(intervals, new_interval);
  for (auto i : x) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
