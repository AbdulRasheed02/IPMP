#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;
int strcompare(string s1, string s2)
{
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    int length1 = s1.length();
    int length2 = s2.length();
    int i;
    for (i = 0; i < length1 && i < length2; i++)
    {

        if (s1[i] == s2[i])
        {
        }
        else
        {
            break;
        }
    }
    if (s1[i] == s2[i])
    {
        return 0;
    }
    if (s1[i] < s2[i])
    {
        return -1;
    }

    return 1;
}
int main()
{
    string s1 = "GeeksforGeeks";
    string s2 = "geeksforgeeks";
    int result = strcompare(s1, s2);
    if (result == 0)
    {
        cout << "s1=s2";
    }
    else if (result == -1)
    {
        cout << "s1<s2";
    }
    else
    {
        cout << "s1>s2";
    }

    return 0;
}