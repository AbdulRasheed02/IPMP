#include <iostream>
#include "tree.cpp"
using namespace std;
int leafCount(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return leafCount(root->left) + leafCount(root->right);
}
int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    int leafs = leafCount(root);
    cout << leafs;
    return 0;
}
