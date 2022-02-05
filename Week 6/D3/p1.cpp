#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> umap;
void findPermutation(string a, int left, int right)
{
    if (left == right)
    {
        umap[a]++;
        if (umap[a] == 1)
        {
            cout << a << " ";
        }
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(a[left], a[i]);
            findPermutation(a, left + 1, right);
            swap(a[left], a[i]);
        }
    }
}

int main()
{
    string str = "AABC";
    int n = str.length() - 1;
    findPermutation(str, 0, n);
    return 0;
}