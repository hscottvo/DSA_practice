#include <iostream>
#include <queue>
#include <utility>
// #include <math>
#include <set>
#include <vector>

using namespace std;

bool valid(int i, int j, int n, int queen_x, int queen_y)
{
    // oob
    if (i <= 0 || j <= 0 || i > n || j > n)
    {
        return false;
    }

    // rook
    if (j == queen_x || i == queen_y)
    {
        return false;
    }

    // bishop
    if (abs(j - queen_x) == abs(i - queen_y))
    {
        return false;
    }

    // else
    return true;
}

bool is_visited(pair<int, int> query, set<pair<int, int>> &check)
{
    return check.find(query) != check.end();
}

int main()
{
    int n, queen_x, queen_y, king_x, king_y, end_x, end_y;
    pair<int, int> curr_coord;
    std::cin >> n >> queen_x >> queen_y >> king_x >> king_y >> end_x >> end_y;
    // priority_queue<pair<int, int>> pq;
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;

    q.push(make_pair(king_x, king_y));
    vector<pair<int, int>> dirs;
    int horiz[] = {-1, 0, 1};
    int vert[] = {-1, 0, 1};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (vert[i] == 0 && horiz[j] == 0)
            {
                continue;
            }
            else
            {
                dirs.push_back(make_pair(horiz[i], vert[j]));
            }
        }
    }

    while (!q.empty())
    {
        curr_coord = q.front();
        q.pop();
        if (curr_coord.first == end_x && curr_coord.second == end_y)
        {
            std::cout << "YES" << endl;
            return 0;
        }

        for (auto item : dirs)
        {
            pair<int, int> new_coord = make_pair(curr_coord.first + item.first, curr_coord.second + item.second);
            if (valid(new_coord.first, new_coord.second, n, queen_x, queen_y) && !is_visited(new_coord, visited))
            {
                visited.insert(new_coord);
                cout << new_coord.first << ", " << new_coord.second << endl;
                q.push(new_coord);
            }
        }
    }
    std::cout << "NO" << endl;

    return 0;
}