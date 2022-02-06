#include <iostream>
using namespace std;
int main()
{
    string s = "GeeksforGeeks";
    int array[256];
    for (int i = 0; i < 256; i++)
    {
        array[i] = -1;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (array[s[i]] == -1)
        {
            array[s[i]] = i;
        }
        else
        {
            array[s[i]] = -2;
        }
    }
    int minIndex = INT_MAX;
    for (int i = 0; i < 256; i++)
    {
        if (array[i] > 0)
        {
            minIndex = min(array[i], minIndex);
        }
    }
    cout << s[minIndex];
    return 0;
}