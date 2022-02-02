#include <iostream>
#include <algorithm>
using namespace std;
void majorityElement(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (count(a, a + n, a[i]) > (n / 2))
        {
            cout << "Majority Element: " << a[i];
            return;
        }
    }
    cout << "No Majority Element";
}
int main()
{
    int n = 9;
    int a[n] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    majorityElement(a, n);
    return 0;
}