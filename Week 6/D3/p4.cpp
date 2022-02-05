#include <iostream>
using namespace std;
float median(int array[], int n)
{
    if (n % 2 == 0)
    {
        return (1.0 * (array[(n / 2) - 1] + array[n / 2])) / 2;
    }
    else
    {
        return array[n / 2];
    }
}
float findMedian(int a[], int b[], int n)
{
    if (n == 1)
    {
        return (a[0] + b[0]) / 2;
    }
    if (n == 2)
    {
        return (1.0 * (max(a[0], b[0]) + min(a[1], b[1]))) / 2;
    }
    float meda = median(a, n);
    float medb = median(b, n);

    if (meda == medb)
    {
        return meda;
    }
    if (meda < medb)
    {
        if (n % 2 == 0)
        {
            return findMedian(a + (n / 2 - 1), b, (n - n / 2 + 1));
        }
        else
        {
            return findMedian(a + n / 2, b, n - n / 2);
        }
    }
    // medb < meda
    if (n % 2 == 0)
    {
        return findMedian(b + n / 2 - 1, a, n - n / 2 + 1);
    }

    return findMedian(b + n / 2, a, n - n / 2);
}
int main()
{
    int n = 4;
    int a[n] = {1, 2, 3, 6};
    int b[n] = {4, 6, 8, 10};
    float median = findMedian(a, b, n);
    cout << "Median of Sorted Array: " << median;

    return 0;
}