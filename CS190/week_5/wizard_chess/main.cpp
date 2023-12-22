#include <iostream>
#include <utility>
#include <string>
#include <limits>

void reset_board(int **dp)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            dp[i][j] = std::numeric_limits<int>::max();
        }
    }
}

void print_dp(int **dp)
{
    for (int i = 7; i >= 0; i--)
    {
        // std::cout << (char)('a' + i) << ' ';
        std::cout << i + 1 << ' ';
        for (int j = 0; j < 8; j++)
        {
            if (dp[i][j] == std::numeric_limits<int>::max())
            {
                std::cout << "inf" << '\t';
            }
            else
            {
                std::cout << dp[i][j] << '\t';
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << (char)('a' + i) << '\t';
    }
    std::cout << std::endl;
}

std::pair<int, int> parse(std::string x)
{
    // return std::make_pair(int(x.at(0)) - 97, int(x.at(1)) - 48);
    return std::make_pair(int(x.at(1)) - 49, int(x.at(0)) - 97);
}

bool valid(int **dp, int i, int j)
{
    if (i < 0 || i > 7 || j < 0 || j > 7)
        return false;
    if (dp[i][j] == -1)
        return false;
    return true;
}

void recurse(int **dp, int i, int j, int moves, int end_i, int end_j)
{
    // std::cout << "i: " << i << ", j: " << j << std::endl;
    if (!valid(dp, i, j))
        return;

    // update mins
    if (moves < dp[i][j])
    {
        dp[i][j] = moves;
    }
    else
    {
        return;
    }

    if (i == end_i && j == end_j)
        return;

    recurse(dp, i - 2, j + 1, moves + 1, end_i, end_j); // up 2 right 1
    recurse(dp, i - 2, j - 1, moves + 1, end_i, end_j); // up 2 left 1
    recurse(dp, i - 1, j + 2, moves + 1, end_i, end_j); // up 1 right 2
    recurse(dp, i - 1, j - 2, moves + 1, end_i, end_j); // up 1 left 2
    recurse(dp, i + 2, j + 1, moves + 1, end_i, end_j); // down 2 right 1
    recurse(dp, i + 2, j - 1, moves + 1, end_i, end_j); // down 2 left 1
    recurse(dp, i + 1, j + 2, moves + 1, end_i, end_j); // down 1 right 2
    recurse(dp, i + 1, j - 2, moves + 1, end_i, end_j); // down 1 left 2
}

int main()
{
    int t = 1;
    std::string curr_string;
    int **dp;
    dp = new int *[8];
    for (int i = 0; i < 8; i++)
    {
        dp[i] = new int[8];
    }
    reset_board(dp);
    int board_num = 1;
    while (std::cin >> t)
    {
        if (t == -1)
            break;
        // std::cout << "t: " << t << std::endl;
        // std::cout << "Blocked: ";
        for (int i = 0; i < t; i++)
        {
            std::cin >> curr_string;
            // std::cout << curr_string << " ";
            std::pair<int, int> curr_block = parse(curr_string);
            dp[curr_block.first][curr_block.second] = -1;
        }
        // std::cout << std::endl;
        std::cin >> curr_string;
        // std::cout << "Start: " << curr_string;
        std::pair<int, int> start = parse(curr_string);
        std::cin >> curr_string;
        // std::cout << "End: " << curr_string << std::endl;
        std::pair<int, int> end = parse(curr_string);

        // std::cout << curr_string << std::endl;
        // std::cout << "test";
        // std::pair<int, int> x = parse(start);
        // dp[start.first][start.second] = 0;
        // x = parse(end);
        // dp[end.first][end.second] = 0;
        recurse(dp, start.first, start.second, 0, end.first, end.second);

        std::cout << "Board " << board_num << ": ";

        if (dp[end.first][end.second] == -1 || dp[end.first][end.second] == std::numeric_limits<int>::max())
        {
            std::cout << "not reachable" << std::endl;
        }
        else
        {
            std::cout << dp[end.first][end.second] << " moves" << std::endl;
        }
        board_num += 1;
        // print_dp(dp);
        reset_board(dp);
    }
    return 0;
}