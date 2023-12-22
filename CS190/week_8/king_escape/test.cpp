#include <iostream>

int main()
{

    int a[] = {-1, 0, 1};
    int b[] = {-1, 0, 1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i] == 0 && b[j] == 0)
            {
                continue;
            }
            std::cout << "(" << a[i] << ", " << b[j] << ")" << std::endl;
        }
    }
}