#include <iostream>
#include <vector>

using namespace std;

void draw_basic(vector<vector<char>> &table, unsigned int row, unsigned int col)
{
    vector<vector<char>> block_template = {{46, 46, 43, 45, 45, 45, 43},
                                           {46, 47, ' ', ' ', ' ', 47, 124},
                                           {43, 45, 45, 45, 43, ' ', 124},
                                           {124, ' ', ' ', ' ', 124, ' ', 43},
                                           {124, ' ', ' ', ' ', 124, 47},
                                           {43, 45, 45, 45, 43}};

    for (unsigned int i = 0; i < block_template.size(); i++)
    {
        for (unsigned int j = 0; j < block_template.at(i).size(); j++)
        {
            if (block_template.at(i).at(j) == 46)
                continue;
            table.at(i + row).at(j + col) = block_template.at(i).at(j);
        }
    }
}

// col conversion: col = 4x + 2z
// row conversion: row = height-6 - (3y + 2z)
void draw_iso(vector<vector<char>> &table, unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int row;
    unsigned int col;

    row = table.size() - 6 - (3 * y + 2 * z);
    col = 4 * x + 2 * z;

    // cout << "Drawing to (" << col << ", " << row << ")" << endl;
    draw_basic(table, row, col);
    // cout << "Finished drawing to (" << col << ", " << row << ")" << endl;
}

void fill_left(vector<vector<char>> &table)
{
    for (unsigned int i = 0; i < table.size(); i++)
    {
        for (unsigned int j = 0; j < table.at(i).size(); j++)
        {
            if (table.at(i).at(j) != ' ')
            {
                break;
            }
            table.at(i).at(j) = 46;
        }
    }
}

void fill_right(vector<vector<char>> &table)
{
    for (unsigned int i = 0; i < table.size(); i++)
    {
        for (unsigned int j = table.at(0).size() - 1; j >= 0; j--)
        {
            if (table.at(i).at(j) != ' ')
            {
                break;
            }
            table.at(i).at(j) = 46;
        }
    }
}
void fill_down(vector<vector<char>> &table)
{
    for (unsigned int j = 0; j < table.at(0).size(); j++)
    {
        for (unsigned int i = 0; i < table.size(); i++)
        {
            if (table.at(i).at(j) != ' ' && table.at(i).at(j) != '.')
            {
                break;
            }
            table.at(i).at(j) = 46;
        }
    }
}

template <class T>
void print_table(vector<vector<T>> table)
{
    for (unsigned int i = 0; i < table.size(); i++)
    {
        for (unsigned int j = 0; j < table.at(i).size(); j++)
        {
            cout << table.at(i).at(j);
        }
        cout << endl;
    }
}

/*
y     z
|    /
|   /
|  /
| /
|/
+_____________ x
*/

// col conversion: col = 4x + 2z
// row conversion: row = height-6 - (3y + 2z)

int main()
{
    // width = 5x + 2z
    // height = (3y + 1) + 2z

    unsigned int x, z, temp, height, width;
    cin >> z >> x;
    height = 0;
    vector<vector<unsigned int>> input(z, vector<unsigned int>(x));
    for (unsigned int i = 0; i < z; i++)
    {
        for (unsigned int j = 0; j < x; j++)
        {
            cin >> temp;
            input.at(i).at(j) = temp;
            // height of block from front + iso
            unsigned int new_height = 3 * temp + 3;
            new_height += 2 * (z - i - 1);
            height = max(height, new_height);
        }
    }
    width = 4 * x + 1 + 2 * z;
    // cout << height << endl;
    // print_table(input);

    vector<vector<char>>
        table(height, vector<char>(width, ' '));

    for (unsigned int i = 0; i < z; i++)
    {
        for (unsigned int j = 0; j < x; j++)
        {
            for (unsigned int k = 0; k < input.at(i).at(j); k++)
            {
                draw_iso(table, j, k, z - i - 1);
            }
        }
    }
    // draw_basic(table, 14, 0);

    fill_left(table);
    fill_down(table);
    fill_right(table);

    print_table(table);

    return 0;
}