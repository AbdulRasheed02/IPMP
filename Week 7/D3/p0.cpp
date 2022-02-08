#include <iostream>
#include "heap.cpp"
using namespace std;
int main()
{
    int k = 3;
    int n = 4;
    int a[k][n] = {{1, 3, 5, 7},
                   {2, 4, 6, 8},
                   {0, 9, 10, 11}};
    int result[n * k];
    heap h;

    for (int i = 0; i < k; i++)
    {
        h.add(a[i][0], i, 0);
    }

    int i, j;
    for (int resultIndex = 0; resultIndex < n * k; resultIndex++)
    {
        heapNode min;
        min = h.poll();
        result[resultIndex] = min.data;
        i = min.indexk;
        j = min.indexn;
        if (j + 1 < n)
        {
            h.add(a[i][j + 1], i, j + 1);
        }
        else
        {
            h.add(INT_MAX, i, j + 1);
        }
    }

    for (int x = 0; x < n * k; x++)
    {
        cout << result[x] << " ";
    }

    return 0;
}