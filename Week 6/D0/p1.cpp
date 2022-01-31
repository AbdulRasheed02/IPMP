#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;
int convert(string s)
{
    int value = 0;
    int n = s.size();
    int ptr = 0;
    int sign = 1;
    if (s[0] == '-')
    {
        sign = -1;
        ptr++;
    }
    for (int i = ptr; i < n; i++)
    {
        int digit = s[i] - '0';
        // cout << digit << " ";
        if (digit <= 9 && digit >= 0)
        {
            value = value * 10 + digit;
        }
        else
        {
            return 0;
        }
    }
    return sign * value;
}
int main()
{
    string s = "-123456";
    int x = convert(s);
    cout << x;

    return 0;
}