#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long n, school_num, score;
    cin >> n;
    long scores[] = {0, 0, 0};
    long students[] = {0, 0, 0};

    for (long i = 1; i <= n; i++)
    {
        cin >> school_num >> score;
        if (score > scores[school_num - 1])
        {
            scores[school_num - 1] = score;
            students[school_num - 1] = i;
        }
    }

    cout << students[0] << endl
         << students[1] << endl
         << students[2] << endl;
}