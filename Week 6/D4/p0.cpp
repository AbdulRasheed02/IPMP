#include <iostream>
using namespace std;
string func(string s)
{
    string ans;
    int count = 1;
    char c = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            count++;
        }
        else
        {
            ans.push_back(c);
            ans.push_back(count + '0');
            c = s[i];
            count = 1;
        }
    }
    ans.push_back(c);
    ans.push_back(count + '0');
    return ans;
}
int main()
{
    string s = "wwwwaaadexxxxxx";
    string ans = func(s);

    cout << ans;

    return 0;
}