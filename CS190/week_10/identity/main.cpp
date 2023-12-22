#include <iostream>
#include <algorithm>

using namespace std;

bool valid(long i, long j)
{
    return i >= 0 && j >= 0;
}

bool check_identity(long i, long j, long dist, long **left_table, long **up_table)
{
    bool ret = true;

    if (!valid(i - 1, j - 1))
    {
        return false;
    }

    return left_table[i][j - 1] >= dist && up_table[i - 1][j] >= dist;

    return ret;
}

int main()
{

    long n, val;
    long max_val = 0;
    cin >> n;
    // long input_table[n][n];
    long **input_table = new long *[n];
    for (int i = 0; i < n; i++)
    {
        input_table[i] = new long[n];
        // for(int j = 0; j < n; j++) {
        //     input_table[i][j] = 0
        // }
    }
    long **output_table = new long *[n];
    for (int i = 0; i < n; i++)
    {
        output_table[i] = new long[n];
        for (int j = 0; j < n; j++)
        {
            output_table[i][j] = 0;
        }
    }
    long **left_table = new long *[n];
    for (int i = 0; i < n; i++)
    {
        left_table[i] = new long[n];
        for (int j = 0; j < n; j++)
        {
            left_table[i][j] = 0;
        }
    }
    long **up_table = new long *[n];
    for (int i = 0; i < n; i++)
    {
        up_table[i] = new long[n];
        for (int j = 0; j < n; j++)
        {
            up_table[i][j] = 0;
        }
    }

    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < n; j++)
        {
            cin >> val;
            input_table[i][j] = val;
        }
    }

    // for (long i = 0; i < n; i++)
    // {
    //     for (long j = 0; j < n; j++)
    //     {
    //         if (input_table[i][j] == 1)
    //         {
    //             left_table[i][j] = 0;
    //             up_table[i][j] = 0;
    //         }
    //         else
    //         {
    //             if (valid(i - 1, j))
    //             {
    //                 up_table[i][j] = up_table[i - 1][j] + 1;
    //             }
    //             else
    //             {
    //                 up_table[i][j] = 1;
    //             }
    //             if (valid(i, j - 1))
    //             {
    //                 left_table[i][j] = left_table[i][j - 1] + 1;
    //             }
    //             else
    //             {
    //                 left_table[i][j] = 1;
    //             }
    //         }
    //     }
    // }

    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < n; j++)
        {
            if (input_table[i][j] == 1)
            {
                left_table[i][j] = 0;
                up_table[i][j] = 0;
                if (valid(i - 1, j - 1) && check_identity(i, j, output_table[i - 1][j - 1], left_table, up_table))
                {
                    output_table[i][j] = output_table[i - 1][j - 1] + 1;
                }
                else
                {
                    output_table[i][j] = 1;
                }
                max_val = max(max_val, output_table[i][j]);
            }
            else
            {

                if (valid(i - 1, j))
                {
                    up_table[i][j] = up_table[i - 1][j] + 1;
                }
                else
                {
                    up_table[i][j] = 1;
                }
                if (valid(i, j - 1))
                {
                    left_table[i][j] = left_table[i][j - 1] + 1;
                }
                else
                {
                    left_table[i][j] = 1;
                }
            }
        }
    }

    // cout << "In table: " << endl;
    // for (long i = 0; i < n; i++)
    // {
    //     for (long j = 0; j < n; j++)
    //     {
    //         cout << input_table[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "Up table: " << endl;
    // for (long i = 0; i < n; i++)
    // {
    //     for (long j = 0; j < n; j++)
    //     {
    //         cout << up_table[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "Left table: " << endl;
    // for (long i = 0; i < n; i++)
    // {
    //     for (long j = 0; j < n; j++)
    //     {
    //         cout << left_table[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // for (long i = 0; i < n; i++)
    // {
    //     for (long j = 0; j < n; j++)
    //     {
    //         // cout << output_table[i][j] << ' ';
    //         max_val = max(max_val, output_table[i][j]);
    //     }
    //     // cout << endl;
    // }
    // cout << "max: " << max_val << endl;
    cout << max_val << endl;

    return 0;
}