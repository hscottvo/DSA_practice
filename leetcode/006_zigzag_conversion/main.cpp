#include <iostream>
#include <string>

using namespace std;
string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    string ret(s.size(), ' ');
    unsigned int group_size = 2 * numRows - 2;
    unsigned int index = 0;
    unsigned int ret_index = 0;
    unsigned int group_num = 0;
    for (int i = 0; i < numRows; i++)
    {
        index = i;
        group_num = 0;
        while (index < s.size())
        {
            // top or bottom row
            cout << "Checking index " << index << endl;
            if (i % (numRows - 1) == 0)
            {
                ret.at(ret_index) = s.at(index);
                ret_index++;
                if (ret_index >= s.size())
                {
                    return ret;
                }
                index += group_size;
            }
            // in the middle
            else
            {
                ret.at(ret_index) = s.at(index);
                ret_index++;
                if (ret_index >= s.size())
                {
                    return ret;
                }
                // go to the next element, which is guaranteed to be in the diagonal
                index += group_size - i * 2;
                if (index < s.size())
                {
                    cout << "Checking index " << index << endl;
                    ret.at(ret_index) = s.at(index);
                    ret_index++;
                    if (ret_index >= s.size())
                    {
                        return ret;
                    }
                }

                // go to the next group
                group_num++;
                index = group_num * group_size + i;
                // cout << "index: "<< index << endl;
            }
        }
    }
    return ret;
}

int main()
{
    string s;
    int rows;
    cin >> s >> rows;

    cout << s << " turns into:" << endl
         << convert(s, rows) << endl;
    return 0;
}