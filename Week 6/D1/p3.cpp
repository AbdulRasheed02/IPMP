#include <iostream>
using namespace std;
bool isMajority(int a[], int n, int x)
{
    int middleIndex = n / 2;
    if (a[middleIndex] == x)
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
    int n = 7;
    int a[n] = {1, 2, 3, 3, 3, 3, 10};
    int x = 3;
    if (isMajority(a, n, x))
    {
        cout << x << " is a Majority Element";
    }
    else
    {
        cout << x << " is not Majority Element";
    }

    return 0;
}