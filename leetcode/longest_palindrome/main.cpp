#include <iostream>
#include <string>
#include <vector>

using namespace std;
void print_2d(vector<vector<bool>> in)
{
    for (unsigned int i = 0; i < in.size(); i++)
    {
        for (unsigned int j = 0; j < in.size(); j++)
        {
            cout << in.at(i).at(j) << ' ';
        }
        cout << endl;
    }
}

string solve(string str)
{
    unsigned int delta = 0;
    unsigned int j;
    unsigned int ret_l;
    unsigned int ret_r;
    vector<vector<bool>> dp(str.size(), vector<bool>(str.size(), false));
    for (unsigned int start_col = 0; start_col < str.size(); start_col++)
    {
        delta = str.size() - start_col;
        // cout << "(" << start_col << ", " << delta << ")\n";
        for (unsigned int i = 0; i < delta; i++)
        {
            j = start_col + i;
            // 1-length substrings always palindrome
            if (i == j)
            {
                // cout << "i: " << i << " j: " << j << " case 1" << endl;
                ret_l = i;
                ret_r = j;
                dp.at(i).at(j) = true;
            }
            // 2-length palindrome if both chars same
            else if (i == j - 1)
            {
                // cout << "i: " << i << " j: " << j << " case 2" << endl;
                if (str.at(i) == str.at(j))
                {
                    ret_l = i;
                    ret_r = j;
                    dp.at(i).at(j) = true;
                }
            }
            // if 2 outer are the same and the inside is a palindrome, then this is also a palindrome
            else
            {
                // cout << "i: " << i << " j: " << j << " case 3" << endl;
                // cout << "i: " << i << " j: " << j << " i+1: " << i + 1 << " j+1: " << j + 1 << endl;
                if (dp.at(i + 1).at(j - 1) && str.at(i) == str.at(j))
                {
                    ret_l = i;
                    ret_r = j;
                    dp.at(i).at(j) = true;
                }
            }
        }
        delta += 1;
    }
    return str.substr(ret_l, ret_r - ret_l + 1);
}

int main()
{
    string str;
    cin >> str;

    // cout << "word: " << str << endl;
    cout << solve(str) << endl;
    return 0;
}