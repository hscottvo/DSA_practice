#include <iostream>
#include <vector>

using namespace std;

void solve(long n)
{
    vector<long> vec;
    long temp;
    while (n--)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    for (unsigned long i = 1; i < vec.size() - 1; i++)
    {
        unsigned long j, k;
        for (j = 0; j < i; j++)
        {
            if (vec.at(j) < vec.at(i))
            {
                break;
            }
        }
        if (j >= i)
        {
            continue;
        }
        for (k = i + 1; k < vec.size(); k++)
        {
            if (vec.at(k) < vec.at(i))
            {
                cout << "YES" << endl
                     << j + 1 << ' ' << i + 1 << ' ' << k + 1 << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;

    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << ' ';
    }
    cout << endl;
}

int main()
{

    long n, t;

    cin >> t;

    while (t--)
    {
        cin >> n;
        solve(n);
    }

    return 0;
}