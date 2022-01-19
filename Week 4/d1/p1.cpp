#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    int a[n] = {12, 11, 10, 5, 6, 2, 30};
    int min = a[0];
    int minim = min;
    int length = 1;
    int max = INT32_MAX;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == min)
        {
            continue;
        }
        else if (a[i] < min)
        {
            min = a[i];
            continue;
        }
        else if (a[i] < max)
        {
            max = a[i];
            minim = min;
        }
        else if (a[i] > max)
        {
            cout << minim << "," << max << "," << a[i];
            return 0;
        }
    }

    cout << "No Triplet";
    return 0;
}