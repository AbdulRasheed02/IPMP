#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s = "GeeksQuiz";
    int array[256];
    for (int i = 0; i < 256; i++)
    {
        array[i] = -1;
    }
    for (int i = 0; i < s.size(); i++)
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
        if (array[i] >= 0)
        {
            minIndex = min(minIndex, array[i]);
        }
    }
    if (minIndex == INT_MAX)
    {
        cout << "No element has frequency of 1";
    }
    else
    {
        cout << s[minIndex];
    }

    return 0;
}