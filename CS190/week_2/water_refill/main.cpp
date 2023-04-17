// m faucets to fill containers
// 1 water/s each faucet
// fauce can only be used by 1 student at a time
// n students
// students ordered from 1 to n, go in order
// array of water per student
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int left, int right) { return left > right; }

void reduce(vector<int> &vec, int reduce)
{
  for (unsigned int i = 0; i < vec.size(); i++)
  {
    vec.at(i) -= reduce;
  }
}

int main()
{
  // priority_queue<int, vector<int>, Compare> pq;
  vector<int> vec;
  queue<int> q;
  int n, m, temp;

  int ret = 0;

  cin >> n >> m;
  int last_index = m - 1;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    q.push(temp);
  }

  // while(!q.empty()) {
  // 	cout << "num: " << q.front() << endl;
  // 	q.pop();
  // }
  for (int i = 0; i < m; i++)
  {
    // pq.push(q.front());
    vec.push_back(q.front());
    q.pop();
  }

  while (!vec.empty())
  {
    sort(vec.begin(), vec.end(), compare);
    // cout << vec.at(last_index) << endl;

    ret += vec.at(last_index);
    reduce(vec, vec.at(last_index));
    vec.pop_back();
    last_index--;
    if (!q.empty())
    {
      vec.push_back(q.front());
      last_index++;
      q.pop();
    }
  }

  cout << ret << endl;

  return 0;
}