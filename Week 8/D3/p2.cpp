#include <iostream>
#include "tree.cpp"
#include <unordered_map>
using namespace std;
unordered_map<int, int> umap;
void pathSum(node *root, int sum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        umap[sum + root->value]++;
    }
    pathSum(root->left, sum + root->value);
    pathSum(root->right, sum + root->value);
}
int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(2);
    pathSum(root, 0);
    int input;
    cin >> input;
    // for (auto it = umap.begin(); it != umap.end(); it++)
    // {
    //     cout << it->first << " ";
    // }
    if (umap[input] > 0)
    {
        cout << boolalpha << true;
    }
    else
    {
        cout << boolalpha << false;
    }

    return 0;
}