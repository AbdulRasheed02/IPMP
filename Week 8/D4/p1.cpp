#include <iostream>
#include "tree.cpp"
using namespace std;

node *buildTree(int inorder[], int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    int maxIndex = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (inorder[i] > inorder[maxIndex])
        {
            maxIndex = i;
        }
    }

    node *root = new node(inorder[maxIndex]);

    if (left == right)
    {
        return root;
    }

    root->left = buildTree(inorder, left, maxIndex - 1);
    root->right = buildTree(inorder, maxIndex + 1, right);

    return root;
}
int main()
{
    int n = 5;
    int inorder[n] = {5, 10, 40, 30, 28};
    node *root = buildTree(inorder, 0, n - 1);
    tree t;
    t.inorder(root);

    return 0;
}