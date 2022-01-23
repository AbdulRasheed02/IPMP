#include <iostream>
using namespace std;
int maxLengthBitonic(int array[], int n)
{
    if (n == 1)
    {
        return 1;
    }
    int adesc[n];
    int ainc[n];
    ainc[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int count = 1;
        int j = i;
        while (j >= 1 && array[j - 1] < array[j])
        {
            count++;
            j--;
        }
        ainc[i] = count;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ainc[i] << " ";
    // }
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        int j = i;
        while (j < n - 1 && array[j + 1] < array[j])
        {
            count++;
            j++;
        }
        adesc[i] = count;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << adesc[i] << " ";
    // }
    int maxLength = ainc[0] + adesc[0] - 1;
    for (int i = 1; i < n; i++)
    {
        if (ainc[i] + adesc[i] - 1 > maxLength)
        {
            maxLength = ainc[i] + adesc[i] - 1;
        }
    }
    return maxLength;
}
int main()
{
    int n = 6;
    int a[n] = {12, 4, 78, 90, 45, 23};
    int maxBitonicLength = maxLengthBitonic(a, n);
    cout << maxBitonicLength;
    return 0;
}