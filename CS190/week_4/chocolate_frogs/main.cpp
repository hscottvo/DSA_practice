#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<long, long> cache;
    long curr;
    int n;
    cin >> n;

    while (n--)
    {
        cin >> curr;
        if (cache.count(curr))
        {
            cache[curr] += 1;
        }
        else
        {
            cache[curr] = 1;
        }
    }
    for (auto i = cache.begin(); i != cache.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    return 0;
}