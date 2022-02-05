#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M[] = {2, 8, -1, -1, -1, 13, -1, 15, 20};
    int N[] = {5, 7, 9, 25};
    int n = size(N);
    int m = size(M);

    int x = m - 1;
    int index;
    while (1)
    {
        while (M[x] != -1)
        {
            x--;
        }
        index = x - 1;
        while (M[index] == -1 && index != -1)
        {
            index--;
        }
        if (index == -1)
        {
            break;
        }
        swap(M[x], M[index]);
    }

    int i = n;
    int j = 0;
    int k = 0;

    while (i < m && j < n)
    {
        if (M[i] <= N[j])
        {
            M[k] = M[i];
            i++;
        }
        else
        {
            M[k] = N[j];
            j++;
        }
        k++;
    }

    while (i < m)
    {
        M[k] = M[i];
        i++;
        k++;
    }
    while (j < n)
    {

        M[k] = N[j];
        j++;
        k++;
    }

    for (int i = 0; i < m; i++)
    {
        cout << M[i] << " ";
    }

    return 0;
}