#include <iostream>
#include "heap.cpp"
using namespace std;
int main()
{
    heap h;
    int n = 6;
    int a[n] = {2, 6, 3, 12, 56, 8};
    int k = 3;
    int i;
    int index = 0;
    for (i = 0; i < k + 1; i++)
    {
        h.add(a[i]);
    }
    for (i; i < n; i++)
    {
        a[index] = h.poll();
        h.add(a[i]);
        index++;
    }
    for (i = 0; i < k + 1; i++)
    {
        a[index] = h.poll();
        index++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}