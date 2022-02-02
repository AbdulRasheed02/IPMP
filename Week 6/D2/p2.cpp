#include <iostream>
using namespace std;
int binarySearch(int a[], int low, int high)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (mid == a[mid])
        {
            return mid;
        }
        if (mid > a[mid])
        {
            return binarySearch(a, mid + 1, high);
        }
        else
            return binarySearch(a, low, mid - 1);
    }
    return -1;
}
int main()
{
    int n = 5;
    int a[n] = {-10, -5, 2, 3, 4};
    int index = binarySearch(a, 0, n - 1);
    cout << index;

    return 0;
}