#include <iostream>
#include <math.h>
using namespace std;
int power[3];
bool factorCheck(int X)
{
    power[0] = power[1] = power[2] = 0;
    while (X % 2 == 0)
    {
        X = X / 2;
        power[0]++;
    }
    while (X % 3 == 0)
    {
        X = X / 3;
        power[1]++;
    }
    while (X % 5 == 0)
    {
        X = X / 5;
        power[2]++;
    }
    if (X == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int cases;
    cin >> cases;
    int Narray[cases];
    int Xarray[cases];
    for (int i = 0; i < cases; i++)
    {
        cin >> Narray[i];
    }
    for (int i = 0; i < cases; i++)
    {
        int X;
        int N = Narray[i];
        int j;
        if (i == 0)
        {
            j = 0;
            X = 0;
            while (j < N)
            {
                X = X + 1;
                while (!factorCheck(X))
                {
                    X = X + 1;
                }
                j++;
            }
        }
        else
        {
            X = Xarray[i - 1];
            j = Narray[i - 1];
            while (j < N)
            {
                X = X + 1;
                while (!factorCheck(X))
                {
                    X = X + 1;
                }
                j++;
            }
        }
        Xarray[i] = X;
        int S = power[0];
        int k = 2;
        if (power[1] >= S)
        {
            S = power[1];
            k = 3;
        }
        if (power[2] >= S)
        {
            S = power[2];
            k = 5;
        }
        int f = ((N * X) / (pow(k, S)));
        int F = f % (1000000007);
        cout << F << ",";
    }

    return 0;
}