#include <iostream>
#include <string>
using namespace std;
void reverseString(string s)
{
    if (s.size() == 0)
    {
        return;
    }
    reverseString(s.substr(1));
    cout << s[0];
}
int main()
{
    string s = "Abdul Rasheed";
    reverseString(s);
    return 0;
}