#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int a[n][n] = {{0, 0, 1, 1},
                   {0, 0, 1, 1},
                   {0, 0, 1, 1},
                   {0, 1, 1, 1}};

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == 1)
            {
                cout << "Max Row:" << i;
                return 0;
            }
        }
    }

    return 0;
}