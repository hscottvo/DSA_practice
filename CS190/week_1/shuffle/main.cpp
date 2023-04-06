#include <iostream>

using namespace std;

int main()
{
    int n;

    int ret = 3;
    int l;
    int r;

    cin >> n;

    while (n--)
    {
        cin >> l;
        cin >> r;
        if (l == ret)
        {
            ret = r;
        }
        else if (r == ret)
        {
            ret = l;
        }
    }
    cout << ret << endl;

    return 0;
}