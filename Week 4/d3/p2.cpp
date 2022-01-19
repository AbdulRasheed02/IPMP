#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 6;
    int a[n] = {1, 60, -10, 70, -80, 85};
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    int l = 0, r = n - 1, sum, minl, minr, min = INT16_MAX;
    while (l < r)
    {
        sum = a[l] + a[r];
        if (abs(sum) < min)
        {
            minl = l;
            minr = r;
            min = sum;
        }
        if (sum < 0)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    cout << "Two Elements:" << a[minl] << "," << a[minr];

    return 0;
}