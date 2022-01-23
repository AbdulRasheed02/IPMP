#include <iostream>
using namespace std;
int main()
{
    int n = 9;
    int array[n] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (array[l] < 0 && array[r] > 0)
        {
            int temp = array[r];
            array[r] = array[l];
            array[l] = temp;
            r--;
            l++;
        }
        else if (array[r] < 0)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    int negIndex = r + 1;
    int lptr = 1;
    int rptr = n - 1;
    while (rptr >= negIndex)
    {
        int temp = array[rptr];
        array[rptr] = array[lptr];
        array[lptr] = temp;
        rptr--;
        lptr = lptr + 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
    return 0;
}