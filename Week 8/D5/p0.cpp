#include <iostream>
#include <map>
#include "tree.cpp"
using namespace std;
const int n = 6;
node *ancestor(int mat[n][n])
{
    multimap<int, int> mp;
    int parent[n] = {0};
    node *nde[n];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += mat[i][j];
        }
        mp.insert(pair<int, int>(sum, i));
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int value = it->second;
        nde[value] = new node(value);
        if (it->first != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (parent[i] == 0 && mat[value][i])
                {
                    if (nde[value]->left == NULL)
                    {
                        nde[value]->left = nde[i];
                    }
                    else
                    {
                        nde[value]->right = nde[i];
                    }
                    parent[i] = 1;
                }
            }
        }
    }
    return nde[n - 1];
}
int main()
{
    int mat[n][n] = {{0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 1, 0},
                     {0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {1, 1, 1, 1, 1, 0}};
    node *root;
    root = ancestor(mat);
    tree t;
    t.inorder(root);

    return 0;
}