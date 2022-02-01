#include <iostream>
#include <string>
using namespace std;
void remove(string s1, string s2)
{
    for (int i = 0; i < s2.length(); i++)
    {
        while (s1.find(s2[i]) != string::npos)
        {
            int index = s1.find(s2[i]);
            s1.replace(index, s1.length() - index, s1, index + 1, s1.length() - index - 1);
        }
    }
    cout << s1;
}

int main()
{
    string s1 = "test string", s2 = "mask";
    remove(s1, s2);

    return 0;
}