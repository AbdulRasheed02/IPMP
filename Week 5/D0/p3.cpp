#include <iostream>
using namespace std;
int main()
{
    int rows = 5;
    int columns = 4;
    int matrix[rows][columns] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
    };
    for (int i = 0; i < rows; i++)
    {
        int a = i;
        int b = 0;
        while (a >= 0 && b < columns)
        {
            cout << matrix[a][b] << " ";
            a--;
            b++;
        }
        cout << endl;
    }
    for (int j = 1; j < columns; j++)
    {
        int a = rows - 1;
        int b = j;
        while (a >= 0 && b < columns)
        {
            cout << matrix[a][b] << " ";
            a--;
            b++;
        }
        cout << endl;
    }
    return 0;
}