#include <iostream>

using namespace std;

int main()
{
    // have to do binary search on y value until areas equal
    // can use std binary search, just need to pass in function

    // intersect of a segment:
    // x = (x1(y-y2) + x2(y1-y)) / (y1-y2)
    int n, x1, y1, x2, y2, x3, y3;

    cin >> n;

    while (n--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    }
    return 0;
}