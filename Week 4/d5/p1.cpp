#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main()
{
    int n = 8;
    int a[n] = {2, 5, 2, 8, 5, 6, 8, 8};
    unordered_map<int, int> mp;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    int index = 0;

    copy(mp.begin(), mp.end(), back_inserter(v));
    sort(v.begin(), v.end(), comparator);

    for (int i = 0; i < v.size(); i++)
    {
        while (v[i].second--)
        {
            a[index] = v[i].first;
            index++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }

    return 0;
}