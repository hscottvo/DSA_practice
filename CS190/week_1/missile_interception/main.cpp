#include <iostream>
#include <cmath>

using namespace std;

double dist_squared(int x1, int y1, int x2, int y2)
{
    return (y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2);
}

int main()
{
    // TODO: get the furthest ones first
    int x1, x2, y1, y2, n, curr_x, curr_y;
    int r_1 = 0;
    int r_2 = 0;
    int dist_1;
    int dist_2;

    cin >> x1 >> y1 >> x2 >> y2 >> n;

    while (n--)
    {
        cin >> curr_x >> curr_y;
        // cout << "(" << curr_x << ", " << curr_y << ")" << endl;
        dist_1 = dist_squared(x1, y1, curr_x, curr_y);
        dist_2 = dist_squared(x2, y2, curr_x, curr_y);
        if (dist_1 <= r_1 || dist_2 <= r_2)
        {
            continue;
        }
        if (dist_1 - r_1 > dist_2 - r_2)
        {
            r_2 += ceil(dist_2) - r_2;
        }
        else
        {
            r_1 += ceil(dist_1) - r_1;
        }
    }
    // cout << dist(x1, y1, x2, y2) << endl;

    cout << r_1 + r_2 << endl;
    return 0;
}
