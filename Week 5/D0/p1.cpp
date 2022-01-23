#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 7;
    int array[n] = {1, -2, -3, 0, 7, -8, -2};
    int maxNow = array[0];
    int minNow = array[0];
    int maxProduct = array[0];

    for (int i = 0; i < n; i++)
    {
        int x = max({array[i], array[i] * maxNow, array[i] * minNow});
        minNow = min({array[i], array[i] * maxNow, array[i] * minNow});
        maxNow = x;
        maxProduct = max(maxProduct, maxNow);
    }

    cout << maxProduct;

    return 0;
}