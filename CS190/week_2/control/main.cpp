#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve()
{
    string s;
    string curr;
    string ret;
    vector<string> ret_vec;
    int prev_colon = 0;
    int curr_length = 0;
    cin >> s;
    // cout << "solving " << s << endl;

    for (unsigned int i = 0; i < s.size(); i++)
    {
        // hex
        if ((s.at(i) >= 48 && s.at(i) <= 57) || (s.at(i) >= 65 && s.at(i) <= 70))
        {
            prev_colon = 0;
            if (curr_length++ > 4)
            {
                return "INVALID";
            }
            else
            {
                curr += s.at(i);
            }
        }

        // colon
        else if (s.at(i) == ':')
        {
            if (prev_colon == 1)
            {
                ret_vec.push_back("FLAG");
            }
            else if (prev_colon > 1)
            {
                return "INVALID";
            }
            else
            {
                if (curr_length > 0)
                {
                    string in(4 - curr_length, '0');
                    curr.insert(0, in);
                    ret_vec.push_back(curr);
                }
                // prev_colon += 1;
            }
            prev_colon += 1;
            curr_length = 0;
            curr = "";
        }
        else
        {
            return "INVALID";
        }
    }

    if (curr_length > 0)
    {
        string in(4 - curr_length, '0');
        curr.insert(0, in);
        ret_vec.push_back(curr);
    }

    for (unsigned int i = 0; i < ret_vec.size() - 1; i++)
    {
        if (ret_vec.at(i) == "FLAG")
        {
            for (unsigned int j = 0; j < 9 - ret_vec.size(); j++)
            {
                ret += "0000:";
            }
        }
        else
        {
            ret += ret_vec.at(i) + ':';
        }
    }
    if (ret_vec.at(ret_vec.size() - 1) == "FLAG")
    {
        for (unsigned int j = 0; j < 9 - ret_vec.size() - 1; j++)
        {
            ret += "0000:";
        }
        ret += "0000";
    }
    else
    {
        ret += ret_vec.at(ret_vec.size() - 1);
    }

    if (ret.size() != 39)
    {
        return "INVALID";
    }

    return ret;
}

int main()
{
    long n;
    cin >> n;

    while (n--)
    {
        cout << solve() << endl;
    }

    return 0;
}