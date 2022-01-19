#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 4;
    int a[n] = {1, 4, 2, 5};
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    int l = 0, r = n - 1, lsum = a[l], rsum = a[r];
    while (l < r)
    {
        // cout << l << "," << r << endl;
        // cout << lsum << "," << rsum << endl;
        if (lsum == rsum && l + 2 == r)
        {
            cout << "Partion Element: " << a[l + 1];
            return 0;
        }
        else if (lsum < rsum && (a[r - 1] < a[l + 1]))
        {
            l++;
            lsum += a[l];
        }
        else
        {
            r--;
            rsum += a[r];
        }
    }
    return 0;
}