#include <iostream>
#include "tree.cpp"
using namespace std;
int sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->value + sum(root->left) + sum(root->right);
}
bool checkSumTree(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    return (root->value == leftsum + rightsum && checkSumTree(root->left) && checkSumTree(root->right));
}
int main()
{
    node *root = new node(26);
    root->left = new node(10);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->right->right = new node(3);

    if (checkSumTree(root))
    {
        cout << "Sum Tree";
    }
    else
    {
        cout << "Not a Sum Tree";
    }

    return 0;
}
