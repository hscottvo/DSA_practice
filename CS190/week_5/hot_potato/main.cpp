#include <iostream>
#include <vector>

using namespace std;

int main()
{

    long n, temp;
    cin >> n;
    vector<long> vec(n, 0);
    vector<long> input;
    for (long i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp - 1);
    }

    for (long i = 0; i < n; i++)
    {
        for (unsigned long j = 0; j < vec.size(); j++)
        {
            vec.at(j) = 0;
        }
        vec.at(i) = 1;
        for (unsigned long j = 0; j < input.size(); j++)
        {
            long curr_player = input.at(j);
            cout << "Player " << curr_player + 1 << " got the potato. They already held it " << vec.at(curr_player) << " times" << endl;
            if (vec.at(curr_player) == 1)
            {
                cout << curr_player + 1 << endl;
                break;
            }
            else
            {
                vec.at(curr_player) += 1;
            }
        }
    }

    return 0;
}