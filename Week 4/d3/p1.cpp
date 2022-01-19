#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int n = 5;
    int a[n] = {0, 10, 2, -10, -20};
    int count = 0;

    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (a[i] - 1 != a[i - 1])
            {
                cout << "Missing Number is: " << a[i] - 1;
                return 0;
            }
        }
    }

    return 0;
}