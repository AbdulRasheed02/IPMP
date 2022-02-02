#include <iostream>
using namespace std;
void majorityElement(int a[], int n)
{
    int count = 1;
    int majorityIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[majorityIndex] == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            count = 1;
            majorityIndex = i;
        }
    }
    int majorityElement = a[majorityIndex];
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (majorityElement == a[i])
        {
            count2++;
        }
    }
    if (count2 > (n / 2))
    {
        cout << "Majority Element: " << majorityElement;
    }
    else
    {
        cout << "No Majority Element";
    }
}
int main()
{
    int n = 9;
    int a[n] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    majorityElement(a, n);
    return 0;
}