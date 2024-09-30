// a few minutes overtime
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void helper(vector<pair<vector<int>, string>> &graph, vector<string> &ret,
            string &word, int idx) {
  if (graph.at(idx).first.size() == 0) {
    string new_string = word + graph.at(idx).second;
    ret.push_back(new_string.substr(1));
    return;
  }

  else {
    word += graph.at(idx).second;
    for (int i = 0; i < graph.at(idx).first.size(); i++) {
      helper(graph, ret, word, graph.at(idx).first.at(i));
    }

    word.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  if (digits.size() == 0) {
    return {};
  }
  vector<string> ret;
  map<char, string> table;
  table.insert({'2', "abc"});
  table.insert({'3', "def"});
  table.insert({'4', "ghi"});
  table.insert({'5', "jkl"});
  table.insert({'6', "mno"});
  table.insert({'7', "pqrs"});
  table.insert({'8', "tuv"});
  table.insert({'9', "wxyz"});

  // first is children list, second is letter
  vector<int> current_frontier;
  vector<int> previous_frontier;
  vector<pair<vector<int>, string>> graph;
  graph.push_back({{}, "."});
  current_frontier = {0};

  for (int i = 0; i < digits.size(); i++) {
    previous_frontier = current_frontier;
    current_frontier = {};
    string curr_digit = table[digits[i]];

    for (auto j : curr_digit) {
      graph.push_back({{}, string(1, j)});
      current_frontier.push_back(graph.size() - 1);
      for (auto parent : previous_frontier) {
        graph.at(parent).first.push_back(graph.size() - 1);
      }
    }
  }

  string str;
  helper(graph, ret, str, 0);

  return ret;
}

int main(int argc, char *argv[]) {

  string digits;

  cin >> digits;

  for (auto i : letterCombinations(digits)) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
