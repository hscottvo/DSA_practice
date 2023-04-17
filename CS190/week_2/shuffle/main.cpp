#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    // n - number of cards
    // r - number of rounds
    // p - start of shuffle
    // c - size of shuffle
    int n, r, p, c;

    cin >> n >> r;
    vector<int> deck(n);
    int idx = 0;

    // populate deck
    for (int i = n; i >= 1; i--)
    {
        deck.at(idx) = i;
        idx++;
    }

    // run each shuffle round
    while (r--)
    {
        cin >> p >> c;

        // create temp vec
        vector<int> move_top(c);
        vector<int> move_down(p - 1);

        // populate the portion that is moving to the top
        for (int i = 0; i < c; i++)
        {
            move_top.at(i) = deck.at(i + p - 1);
        }
        // cout << "section to be moved to top: ";
        // for (unsigned int i = 0; i < move_top.size(); i++)
        // {
        //     cout << move_top.at(i) << ' ';
        // }
        // cout << endl;

        for (unsigned int i = 0; i < move_down.size(); i++)
        {
            move_down.at(i) = deck.at(i);
        }

        for (unsigned int i = 0; i < move_down.size(); i++)
        {
            deck.at(i + c) = move_down.at(i);
        }

        // populate the new top section
        for (unsigned int i = 0; i < move_top.size(); i++)
        {
            deck.at(i) = move_top.at(i);
        }
    }

    // for (unsigned int i = 0; i < deck.size(); i++)
    // {
    //     cout << deck.at(i) << ' ';
    // }
    // cout << endl;

    cout << deck.at(0) << endl;

    return 0;
}

/*

2 5

10 9 8 7 6 5 4 3 2 1

9 8 7 6 5 10 4 3 2 1



*/