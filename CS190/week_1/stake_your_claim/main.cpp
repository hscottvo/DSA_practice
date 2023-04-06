#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool valid(int i, int j, unsigned int r, unsigned int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int dfs(vector<vector<bool>> &vec, int i, int j)
{
    int ret = 1;
    if (vec.at(i).at(j))
    {
        return 0;
    }
    vec.at(i).at(j) = true;

    // if above is a dot, then the next one up is a dot
    if (valid(i - 1, j, vec.size(), vec.at(0).size()) && !vec.at(i - 1).at(j))
    {
        vec.at(i - 1).at(j) = true;
        ret += dfs(vec, i - 2, j);
    }
    // if below ...
    if (valid(i + 1, j, vec.size(), vec.at(0).size()) && !vec.at(i + 1).at(j))
    {
        vec.at(i + 1).at(j) = true;
        ret += dfs(vec, i + 2, j);
    }
    // if left...
    if (valid(i, j - 1, vec.size(), vec.at(0).size()) && !vec.at(i).at(j - 1))
    {
        vec.at(i).at(j - 1) = true;
        ret += dfs(vec, i, j - 2);
    }
    // if right...
    if (valid(i, j + 1, vec.size(), vec.at(0).size()) && !vec.at(i).at(j + 1))
    {
        vec.at(i).at(j + 1) = true;
        ret += dfs(vec, i, j + 2);
    }

    return ret;
}

int main()
{
    int r, c;
    int curr_r, curr_c;
    char temp;
    cin >> r >> c;
    vector<vector<bool>> in_table;
    curr_r = 2 * r + 1;
    while (curr_r--)
    {
        curr_c = 2 * c + 1;
        vector<bool> row_vec;
        while (curr_c--)
        {
            cin >> temp;
            if (temp == '-' || temp == '+' || temp == '|')
            {
                row_vec.push_back(true);
            }
            else
            {
                row_vec.push_back(false);
            }
        }
        in_table.push_back(row_vec);
    }
    // int row_dir[] = {-1, 1, 0, 0};
    // int col_dir[] = {0, 0, -1, 1};
    vector<int> ret;
    // dfs(in_table, 0, 0);
    for (int i = 1; i < 2 * r + 1; i += 2)
    {
        for (int j = 1; j < 2 * c + 1; j += 2)
        {
            // cout << in_table.at(i).at(j) << ' ';
            if (!in_table.at(i).at(j))
            {
                ret.push_back(dfs(in_table, i, j));
            }
        }
    }

    sort(ret.begin(), ret.end());

    for (int i = ret.size() - 1; i >= 0; i--)
    {
        cout << ret.at(i) << ' ';
    }
    cout << endl;
    return 0;
}