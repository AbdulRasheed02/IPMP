#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    string s1 = "silent";
    string s2 = "listen";

    sort(s1.begin(), s1.begin() + s1.size());
    sort(s2.begin(), s2.begin() + s2.size());

    if (s1 == s2)
    {
        cout << "Anagram";
    }
    else
    {
        cout << "Not Anagram";
    }

    return 0;
}