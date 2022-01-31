#include <iostream>
using namespace std;
int binarySearch(int a[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (key == a[mid])
    {
        return mid;
    }
    else if (key > a[mid])
    {
        return binarySearch(a, key, mid + 1, high);
    }

    return binarySearch(a, key, low, mid - 1);
}
int pivot(int a[], int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    if (low == high)
    {
        return low;
    }
    int mid = (low + high) / 2;
    if (mid < high && a[mid] > a[mid + 1])
    {
        return mid;
    }
    if (mid > low && a[mid] < a[mid - 1])
    {
        return mid - 1;
    }
    if (a[low] >= a[mid])
    {
        return pivot(a, low, mid - 1);
    }
    return pivot(a, mid + 1, high);
}
int main()
{
    int n = 9;
    int a[n] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int pivotIndex = 0;
    int key = 3;
    int keyIndex = 0;
    pivotIndex = pivot(a, 0, n - 1);
    // cout << pivotIndex << endl;
    if (pivotIndex == -1)
    {
        keyIndex = binarySearch(a, key, 0, n - 1);
    }
    else if (a[pivotIndex] == key)
    {
        keyIndex = pivotIndex;
    }
    else if (key >= a[0])
    {
        keyIndex = binarySearch(a, key, 0, pivotIndex - 1);
    }
    else
    {
        keyIndex = binarySearch(a, key, pivotIndex + 1, n - 1);
    }
    cout << keyIndex;
    return 0;
}