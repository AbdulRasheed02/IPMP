#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n = 30;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int sum = j * j + i * i;
            int c = sqrt(sum);
            if (c * c == sum && c <= n)
            {
                cout << i << "," << j << "," << c << endl;
                count++;
            }
        }
    }
    cout << "No.Of Triplets: " << count;
    return 0;
}