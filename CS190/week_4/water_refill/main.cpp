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

bool compare(long long left, long long right) { return left > right; }

void reduce(vector<long long> &vec, long long reduce)
{
  for (unsigned long long i = 0; i < vec.size(); i++)
  {
    vec.at(i) -= reduce;
  }
}

int main()
{
  // priority_queue<long long, vector<long long>, Compare> pq;
  vector<long long> vec;
  queue<long long> q;
  long long n, m, temp;

  long long ret = 0;

  cin >> n >> m;
  long long last_index = m - 1;
  for (long long i = 0; i < n; i++)
  {
    cin >> temp;
    q.push(temp);
  }

  // while(!q.empty()) {
  // 	cout << "num: " << q.front() << endl;
  // 	q.pop();
  // }
  for (long long i = 0; i < m; i++)
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