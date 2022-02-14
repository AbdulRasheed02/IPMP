#include <iostream>
#include "tree.cpp"
using namespace std;
int preorderIndex = 0;
node *buildTree(int inorder[], int preorder[], int left, int right)
{
    if (left > right)
    {
        return NULL;
    }
    node *root = new node(preorder[preorderIndex++]);

    if (left == right)
    {
        return root;
    }

    int inorderIndex = 0;
    for (int i = left; i <= right; i++)
    {
        if (root->value == inorder[i])
        {
            inorderIndex = i;
        }
    }
    root->left = buildTree(inorder, preorder, left, inorderIndex - 1);
    root->right = buildTree(inorder, preorder, inorderIndex + 1, right);

    return root;
}
int main()
{
    int n = 6;
    int inorder[n] = {4, 2, 5, 1, 6, 3};
    int preorder[n] = {1, 2, 4, 5, 3, 6};
    node *root = buildTree(inorder, preorder, 0, n - 1);
    tree t;
    t.inorder(root);

    return 0;
}