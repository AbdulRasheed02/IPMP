#include <iostream>
using namespace std;
int main()
{
    int n = 5 + 2;
    int a[n] = {4, 2, 4, 5, 2, 3, 1};
    int xr = a[0];
    for (int i = 1; i < n; i++)
    {
        xr = xr ^ a[i];
    }
    for (int i = 1; i < n - 2 + 1; i++)
    {
        xr = xr ^ i;
    }
    int set_bit = xr & ~(xr - 1);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & set_bit)
        {
            x = x ^ a[i];
        }
        else
        {
            y = y ^ a[i];
        }
    }
    for (int i = 1; i < n - 2 + 1; i++)
    {
        if (i & set_bit)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }
    cout << x << " " << y;

    return 0;
}