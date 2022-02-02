#include <iostream>
using namespace std;
int main()
{
    int n = 9;
    int a[n] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    int startIndex, endIndex;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            startIndex = i;
            break;
        }
    }
    // cout << startIndex << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            endIndex = i;
            break;
        }
    }
    // cout << endIndex << endl;
    int min = startIndex, max = startIndex;
    for (int i = startIndex + 1; i <= endIndex; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
        else if (a[i] < a[min])
        {
            min = i;
        }
    }
    // cout << a[max] << " " << a[min] << endl;
    int minIndex, maxIndex;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[min])
        {
            minIndex = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < a[max])
        {
            maxIndex = i;
            break;
        }
    }
    cout << "Array should be sorted from " << minIndex << " to " << maxIndex;
    return 0;
}