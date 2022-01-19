#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n = 7;
    int a[n] = {0, 2, 3, 6, 3, 6, 0};
    for (int i = 0; i < n; i++)
    {
        a[i]++;
    }
    cout << "Result:";
    for (int i = 0; i < n; i++)
    {
        if (a[abs(a[i]) - 1] >= 0)
        {
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        }
        else
        {
            cout << abs(a[i]) - 1 << ",";
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i]--;
    }

    return 0;
}