// took 6 minutes

#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
  map<char, int> hash;
  for (int i = 0; i < s.size(); i++) {
    hash[s.at(i)]++;
  }

  for (int i = 0; i < t.size(); i++) {
    hash[t.at(i)]--;
  }

  for (auto i : hash) {
    if (i.second != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  cout << isAnagram("anagram", "nagaram") << endl;
  cout << isAnagram("rat", "car") << endl;
  return 0;
}
