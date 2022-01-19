#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int mat[n][n] = {{1, 20, 30, 40},
                     {15, 25, 34, 45},
                     {28, 31, 37, 48},
                     {32, 33, 39, 70}};
    int x = 28;
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {

        if (mat[i][j] == x)
        {
            cout << "Element at Position:"
                 << endl;
            cout << i << "," << j;
            return 0;
        }
        cout << i << "," << j << endl;
        if (mat[i][j] < x)
        {
            i++;
        }
        else if (mat[i][j] > x)
        {
            j--;
        }
    }
    cout << "Element not Found";

    return 0;
}