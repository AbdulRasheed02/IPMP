#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 6;
    int a[n] = {12, 3, 4, 1, 6, 9};
    int sum = 24;
    int l, r;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] > sum)
            {
                r--;
            }
            else if (a[i] + a[l] + a[r] < sum)
            {
                l++;
            }
            else
            {
                cout << "Triplet Exists:" << endl;
                cout << a[i] << "," << a[l] << "," << a[r];
                return 0;
            }
        }
    }
    cout << "Triplet Does not Exist" << endl;
    return 0;
}