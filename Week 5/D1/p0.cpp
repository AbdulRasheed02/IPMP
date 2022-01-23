#include <iostream>
using namespace std;
int main()
{
    int n = 11;
    int a[n] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    int nonZeroCount;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            a[nonZeroCount] = a[i];
            nonZeroCount++;
        }
    }
    int index = nonZeroCount + 1;
    for (int i = index; i < n; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}