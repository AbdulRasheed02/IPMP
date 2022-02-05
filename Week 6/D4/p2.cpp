#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    string s1 = "this is a test string";
    string s2 = "tist";

    int minLength = INT_MAX;
    int start = -1;
    int startIndex = 0;
    int array1[256] = {0};
    int array2[256] = {0};
    int count = 0;

    for (int i = 0; i < s2.length(); i++)
    {
        array2[s2[i]]++;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        array1[s1[i]]++;
        if (s1[i] == s2[count])
        {
            count++;
        }
        if (count == s2.length())
        {
            while (array1[s1[startIndex]] > array2[s1[startIndex]] || array2[s1[startIndex]] == 0)
            {
                if (array1[s1[startIndex]] > array2[s1[startIndex]])
                {
                    array1[s1[startIndex]]--;
                }
                startIndex++;
            }

            int length = i - startIndex + 1;

            if (minLength > length)
            {
                minLength = length;
                start = startIndex;
            }
        }
    }

    cout << minLength << endl;
    cout << s1.substr(startIndex, minLength);
    return 0;
}