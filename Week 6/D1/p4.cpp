#include <iostream>
using namespace std;
int binarySearch(int a[], int low, int high, int key)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (key == a[mid] || (key > a[mid - 1] && key < a[mid + 1] && a[mid - 1] != a[mid + 1]))
        {
            return mid;
        }
        if (key > a[mid])
        {
            return binarySearch(a, mid + 1, high, key);
        }
        else
            return binarySearch(a, low, mid - 1, key);
    }
    if (low == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n = 7;
    int a[n] = {1, 2, 8, 10, 10, 12, 19};
    int x = 119;
    int index = binarySearch(a, 0, n - 1, x);
    if (a[index] == x)
    {
        cout << "Floor and Ceiling: " << x;
    }
    else
    {
        if (index == 0)
        {
            cout << "No Floor,"
                 << "Ceiling:" << a[0];
        }
        else if (index == -1)
        {
            cout << "Floor: " << a[n - 1]
                 << ",No Ceiling";
        }
        else
        {
            if (a[index] > x)
            {
                cout << "Floor: " << a[index - 1] << ",Ceiling:" << a[index];
            }
            else
            {
                cout << "Floor: " << a[index] << ",Ceiling:" << a[index + 1];
            }
        }
    }

    return 0;
}