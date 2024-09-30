#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pwd(vector<string> vec) {
  // cout << "/";
  for (auto i : vec) {
    cout << i << "/";
  }
  cout << endl;
}

void cd(vector<string> &vec, string &cmd) {
  int idx = 0;

  if (cmd == "/") {
    vec = vector<string>(1, "");
    return;
  } else if (cmd.at(0) == '/') {
    vec = vector<string>(1, "");
    idx = 1;
  }

  while (idx != string::npos) {
    int end_idx = cmd.find('/', idx);
    string dir;

    if (end_idx != string::npos) {
      dir = cmd.substr(idx, end_idx - idx);
    } else {
      dir = cmd.substr(idx, cmd.size() - idx);
    }

    if (dir == "..")
      vec.pop_back();

    else {
      vec.push_back(dir);
    }

    if (end_idx == string::npos)
      break;

    idx = end_idx + 1;
  }
}

int main() {
  int n;
  cin >> n;

  vector<string> vec(1, "");

  while (n--) {
    string cmd;
    cin >> cmd;

    if (cmd == "pwd")
      pwd(vec);
    else {
      cin >> cmd;
      cd(vec, cmd);
    }
  }
}
