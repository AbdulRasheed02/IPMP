#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> sets;
    vector<int> set1;
    set1.push_back(1);
    set1.push_back(2);
    set1.push_back(2);
    set1.push_back(3);
    set1.push_back(4);

    vector<int> set2;
    set2.push_back(2);
    set2.push_back(2);
    set2.push_back(3);
    set2.push_back(5);
    set2.push_back(6);

    vector<int> set3;
    set3.push_back(1);
    set3.push_back(3);
    set3.push_back(2);
    set3.push_back(2);
    set3.push_back(6);

    sets.push_back(set1);
    sets.push_back(set2);
    sets.push_back(set3);

    int minElementSetIndex = 0;
    for (int i = 1; i < sets.size(); i++)
    {
        if (sets[i].size() < sets[minElementSetIndex].size())
        {
            minElementSetIndex = i;
        }
    }
    // cout << sets[minElementSetIndex].size();
    map<int, int> umap;
    vector<int> result;
    for (int i = 0; i < sets[minElementSetIndex].size(); i++)
    {
        umap[sets[minElementSetIndex][i]]++;
    }
    // for (auto it = umap.cbegin(); it != umap.cend(); ++it)
    // {
    //     std::cout << it->first << " " << it->second << "\n";
    // }
    for (auto it = umap.cbegin(); it != umap.cend(); ++it)
    {
        int element = it->first;
        int frequency = it->second;
        bool exists = true;
        for (int i = 1; i < sets.size(); i++)
        {
            if (i != minElementSetIndex)
            {
                int frequnecyInSet = count(sets[i].begin(), sets[i].end(), element);
                if (frequnecyInSet)
                {
                    // cout << frequnecyInSet << endl;
                    if (frequnecyInSet < frequency)
                    {
                        frequency = frequnecyInSet;
                    }
                }
                else
                {
                    exists = false;
                    break;
                }
            }
        }
        if (exists)
        {
            for (int i = 0; i < frequency; i++)
            {
                result.push_back(element);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}