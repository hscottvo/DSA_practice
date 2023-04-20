#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, d, m, s;
    // (index, compat)
    pair<long long, long long> upper = make_pair(0, 0);
    pair<long long, long long> lower = make_pair(0, 0);
    long long max_val = 0;
    long long ret = 0;
    // (compatibility, happiness)
    vector<pair<long long, long long>> vec;

    cin >> n >> d;

    while (n--)
    {
        cin >> m >> s;
        vec.push_back(make_pair(m, s));
    }

    sort(vec.begin(), vec.end());

    upper = make_pair(0, vec.at(0).first);
    lower = make_pair(0, vec.at(0).first);
    ret = vec.at(0).second;

    for (unsigned int i = 0; i < vec.size(); i++)
    {
        // cout << vec.at(i).first << ',' << vec.at(i).second << endl;
        upper = make_pair(i, vec.at(i).first);
        max_val += vec.at(upper.first).second;

        while (lower.first < upper.first && upper.second - lower.second >= d)
        {
            // cout << upper.second << " - " << lower.second << " = " << upper.second - lower.second << " is larger than " << d << ". Moving up" << endl;
            max_val -= vec.at(lower.first).second;
            lower = make_pair(lower.first + 1, vec.at(lower.first + 1).first);
        }
        // cout << "From " << lower.second << " to " << upper.second << ": " << max_val << endl;

        ret = max(ret, max_val);
    }
    cout << ret << endl;

    return 0;
}

/*
0 7
11 32
46 8
87 99
99 10

*/