#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n = 5;
    int a[n] = {10, 3, 5, 6, 2};
    int prod[n];
    int product = a[0];

    for (int i = 1; i < n; i++)
    {
        product = product * a[i];
    }
    cout << product << endl;
    for (int i = 0; i < n; i++)
    {
        cout << product * pow(a[i], -1) << ",";
    }

    return 0;
}