#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    string str = "GEEKSFORGEEKS";
    vector<int> v(256, -1);
    int n = str.length();
    int start = 0;
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        start = max(start, v[str[i]] + 1);
        maxLength = max(maxLength, i - start + 1);
        v[str[i]] = i;
    }
    cout << maxLength;
    return 0;
}