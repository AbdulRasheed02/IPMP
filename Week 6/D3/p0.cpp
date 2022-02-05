#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<char, int> umap;
    string s = "test string";
    for (int i = 0; i < s.length(); i++)
    {
        umap[s[i]]++;
    }
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        if (it->second > 1 && it->first != ' ')
        {
            cout << it->first << " = " << it->second << endl;
        }
    }

    return 0;
}