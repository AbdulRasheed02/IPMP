#include <iostream>
using namespace std;
void rotate(int a[], int d, int n)
{
    if (d == 0)
    {
        return;
    }
    for (int i = 0; i < d; i++)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        int temp = a[0];
        for (int i = 1; i < n; i++)
        {
            a[i - 1] = a[i];
        }
        a[n - 1] = temp;
    }
}
int main()
{
    int n = 7;
    int a[n] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    rotate(a, d, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}