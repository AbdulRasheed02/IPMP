#include <iostream>
using namespace std;
int main()
{
    int n = 12;
    int a[n] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int count0, count1, count2;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count0++;
        }
        else if (a[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (count0)
        {
            a[i] = 0;
            count0--;
        }
        else if (count1)
        {
            a[i] = 1;
            count1--;
        }
        else
        {
            a[i] = 2;
            count2--;
        }
        cout << a[i] << ",";
    }
    return 0;
}