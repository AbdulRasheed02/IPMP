#include <iostream>
using namespace std;
int main()
{
    int n = 7;
    int a[n] = {1, 4, 0, 0, 3, 10, 5};
    int sum = 7;
    int left = 0;
    int right = 0;
    int x = a[left];
    while (left <= right && right < n)
    {
        // cout << x << " " << left << " " << right << endl;
        if (x == sum)
        {
            break;
        }
        if (x < sum)
        {
            right++;
            x += a[right];
        }
        else
        {
            x -= a[left];
            left++;
        }
    }
    // cout << x << endl;
    if (x == sum)
    {
        cout << "Index between " << left << " and " << right;
    }
    else
    {
        cout << "No Subarray found";
    }
    return 0;
}