#include <iostream>
using namespace std;
int main()
{
    int i, j;
    cin >> i >> j;
    float water = 2;
    int rows = 5;
    int n = (rows * (rows + 1)) / 2;
    float glass[n];
    glass[0] = water;
    int index = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < row; col++, index++)
        {
            water = glass[index];
            if (water >= 1.0f)
            {
                water = water - 1.0;
            }
            else
            {
                water = 0.0f;
            }
            glass[index + row + 1] += water / 2;
            glass[index + row + 1 + 1] += water / 2;
        }
    }

    cout << glass[i * (i - 1) / 2 + j - 1];
    return 0;
}