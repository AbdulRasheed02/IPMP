#include <iostream>
#include <string.h>

using namespace std;
int main()
{
    int n = 11;
    int a[n] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    bool in1 = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 9)
        {
            in1 = true;
        }
        else
        {
            in1 = false;
            break;
        }
    }
    if (in1)
    {
        string palindrome = "1";
        for (int i = 0; i < n - 1; i++)
        {
            palindrome = palindrome + '0';
        }
        palindrome = palindrome + '1';
        cout << palindrome;
        return 0;
    }

    int mid = n / 2;
    bool left = false;
    int i = mid - 1;
    int j;
    if (n % 2)
    {
        j = mid + 1;
    }
    else
    {
        j = mid;
    }
    while (i >= 0 && a[i] == a[j])
    {
        i--;
        j++;
    }
    if (i < 0 || a[i] < a[j])
    {
        left = true;
    }
    while (i >= 0)
    {
        a[j] = a[i];
        j++;
        i--;
    }
    if (left == true)
    {
        int carry = 1;
        i = mid - 1;

        if (n % 2 == 1)
        {
            a[mid] += carry;
            carry = a[mid] / 10;
            a[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;

        while (i >= 0)
        {
            a[i] += carry;
            carry = a[i] / 10;
            a[i] %= 10;

            a[j++] = a[i--];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }

    return 0;
}
