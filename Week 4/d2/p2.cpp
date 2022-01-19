#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int a[n] = {1, 2, 90, 10, 110};
    int maxDif;
    int min = a[0];
    maxDif = a[1] - a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - min > maxDif)
        {
            maxDif = a[i] - min;
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    cout << "Maximum Difference: " << maxDif;

    return 0;
}