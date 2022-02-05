#include <iostream>
using namespace std;
int binarySearch(int array[], int left, int right)
{
    if (left == right)
    {
        return left;
    }

    if (left + 1 == right)
    {
        if (array[left] >= array[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }

    int mid = left + (right - left) / 2;

    if (array[mid] > array[mid - 1] && array[mid] > array[mid + 1])
    {
        return mid;
    }

    if (array[mid] > array[mid - 1])
    {
        return binarySearch(array, mid + 1, right);
    }
    else
    {
        return binarySearch(array, left, mid - 1);
    }
}

int main()
{
    int n = 5;
    int a[n] = {120, 100, 80, 20, 0};
    int maxIndex = binarySearch(a, 0, n - 1);
    cout << "Max: " << a[maxIndex];
    return 0;
}