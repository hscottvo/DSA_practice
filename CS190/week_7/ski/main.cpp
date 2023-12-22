#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
#include <iterator>

void print_paths(long long **paths, long long r, long long c)
{
    std::cout << "-------------------paths----------------" << std::endl;
    for (long long i = 0; i < r; i++)
    {
        for (long long j = 0; j < c; j++)
        {
            std::cout << paths[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void print_heights(long long **paths, long long r, long long c)
{
    std::cout << "--------------heights----------------" << std::endl;
    for (long long i = 0; i < r; i++)
    {
        for (long long j = 0; j < c; j++)
        {
            std::cout << paths[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool valid(long long i, long long j, long long r, long long c)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

long long get_height(long long **heights, long long i, long long j, long long r, long long c)
{
    if (valid(i, j, r, c))
    {
        return heights[i][j];
    }
    else
        return std::numeric_limits<long long>::max();
}

long long f(long long **heights, long long **paths, long long i, long long j, long long r, long long c, long long prev_height)
{
    if (!valid(i, j, r, c)) // || prev_height < heights[i][j])
    {
        return std::numeric_limits<long long>::min();
    }
    else if (prev_height <= heights[i][j])
    {
        return std::numeric_limits<long long>::min();
    }
    else if (paths[i][j] != -1)
    {
        return paths[i][j];
    }
    else if (heights[i][j] <= get_height(heights, i - 1, j, r, c) &&
             heights[i][j] <= get_height(heights, i + 1, j, r, c) &&
             heights[i][j] <= get_height(heights, i, j - 1, r, c) &&
             heights[i][j] <= get_height(heights, i, j + 1, r, c))
    {
        paths[i][j] = 1;
        return 1;
    }
    else
    {
        long long up = f(heights, paths, i - 1, j, r, c, heights[i][j]) + 1;
        long long down = f(heights, paths, i + 1, j, r, c, heights[i][j]) + 1;
        long long left = f(heights, paths, i, j - 1, r, c, heights[i][j]) + 1;
        long long right = f(heights, paths, i, j + 1, r, c, heights[i][j]) + 1;
        long long dirs[4] = {up, down, left, right};
        paths[i][j] = *std::max_element(dirs, dirs + 4);
        return paths[i][j];
    }
}

int main()
{
    long long r;
    long long c;
    std::cin >> r;
    std::cin >> c;

    long long **heights;
    heights = new long long *[r];
    for (long long i = 0; i < r; i++)
    {
        heights[i] = new long long[c];
    }
    long long **paths;
    paths = new long long *[r];
    for (long long i = 0; i < r; i++)
    {
        paths[i] = new long long[c];
    }

    for (long long i = 0; i < r; i++)
    {
        for (long long j = 0; j < c; j++)
        {
            std::cin >> heights[i][j];
            paths[i][j] = -1;
        }
    }
    for (long long i = 0; i < r; i++)
    {
        for (long long j = 0; j < c; j++)
        {
            f(heights, paths, i, j, r, c, std::numeric_limits<long long>::max());
        }
    }
    long long ret = 0;
    for (long long i = 0; i < r; i++)
    {
        for (long long j = 0; j < c; j++)
        {
            ret = std::max(ret, paths[i][j]);
        }
    }

    for (long long i = 0; i < r; i++)
    {
        delete[] paths[i];
        delete[] heights[i];
    }

    std::cout << ret << std::endl;
    return 0;
}