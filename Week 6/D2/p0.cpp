#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{

    string s = "getting good at coding needs a lot of practice";
    int left = 0;
    int right = 0;
    while (left < s.length())
    {
        while (right < s.length() && s[right] != ' ')
        {
            right++;
        }
        reverse(s.begin() + left, s.begin() + right);
        left = right + 1;
        right = left;
    }
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}