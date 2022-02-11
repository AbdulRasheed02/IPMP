#include "tree.cpp"
#include <iostream>
#include <map>
using namespace std;
void verticalSum(node *root, map<int, int> &mp, int verticalLevel)
{
    if (root == NULL)
    {
        return;
    }
    mp[verticalLevel] += root->value;
    verticalSum(root->left, mp, verticalLevel - 1);
    verticalSum(root->right, mp, verticalLevel + 1);
}
int main()
{
    map<int, int> mp;
    auto iterator = mp.begin();
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    verticalSum(root, mp, 0);

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " - " << it->second << endl;
    }

    return 0;
}