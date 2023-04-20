#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(long long x, long long y)
{
    return sqrt(x * x + y * y);
}

int main()
{
    long long n, s, x, y, k;
    // priority_queue<pair<double, long long>> pq;
    vector<pair<double, long long>> vec;
    pair<double, long long> curr;
    long long needed = 1e6;
    double radius = 0;

    cin >> n >> s;

    needed -= s;

    if (needed <= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    while (n--)
    {
        cin >> x >> y >> k;
        curr = make_pair(dist(x, y), k);
        vec.push_back(curr);
    }
    sort(vec.begin(), vec.end(), [](const pair<double, long long> lhs, pair<double, long long> rhs)
         {
        if(abs(lhs.first - rhs.first) < 1e-6) {
            return lhs.second > rhs.second;
        } else {
            return lhs.first < rhs.first;
        } });

    for (unsigned int i = 0; i < vec.size(); i++)
    {
        // cout << vec.at(i).first << ',' << vec.at(i).second << endl;
        needed -= vec.at(i).second;
        radius = vec.at(i).first;
        if (needed <= 0)
        {
            cout << setprecision(8) << radius << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    // cout << radius << endl;

    return 0;
}