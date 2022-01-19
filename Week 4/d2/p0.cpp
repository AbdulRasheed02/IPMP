#include <iostream>
using namespace std;
int main()
{
    int n = 6;
    int m = n - 1;
    int a[m] = {1, 2, 4, 5, 6};
    int xr = a[0];
    for (int i = 1; i < m; i++)
    {
        xr = xr ^ a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        xr = xr ^ i;
    }
    cout << "Missing Number: " << xr;

    return 0;
}