#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

long solve(long **dp, vector<pair<long, long>> &vec, long budget)
{
    for (unsigned long i = 0; i < vec.size() + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (long i = 0; i < budget + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (unsigned long i = 1; i < vec.size() + 1; i++)
    {
        for (unsigned long j = 1; j < budget + 1; j++)
        {
            if (vec.at(i - 1).first <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec.at(i - 1).first] + vec.at(i - 1).second);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[vec.size()][budget];
}

int main()
{
    long budget, n, a, b;

    cin >> budget >> n;

    long **dp = new long *[n + 1];

    for (long i = 0; i < n + 1; i++)
    {
        dp[i] = new long[budget + 1];
    }

    vector<pair<long, long>> vec;

    for (long i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }
    sort(vec.begin(), vec.end());

    cout << solve(dp, vec, budget) << endl;
    // cout << solve(dp, vec, budget) << endl;
    // for (long i = 0; i < budget + 1; i++)
    // {
    //     solve(dp, vec, budget);
    // }
    // // cout << dp[budget] << endl;
    // cout << solve(dp, vec, budget) << endl;

    return 0;
}