#include <iostream>
#include "tree.cpp"
using namespace std;
int preorderIndex = 0;

node *buildTree(int preorder[], int postorder[], int start, int end, int n)
{
    if (preorderIndex >= n || start > end)
    {
        return NULL;
    }

    node *root = new node(preorder[preorderIndex]);
    preorderIndex++;
    if (start == end)
    {
        return root;
    }

    int postorderIndex;
    for (postorderIndex = start; postorderIndex <= end; postorderIndex++)
    {
        if (postorder[postorderIndex] == preorder[preorderIndex])
        {
            break;
        }
    }

    root->left = buildTree(preorder, postorder, start, postorderIndex, n);
    root->right = buildTree(preorder, postorder, postorderIndex + 1, end - 1, n);

    return root;
}
int main()
{
    int n = 9;
    int preorder[n] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int postorder[n] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    node *root = buildTree(preorder, postorder, 0, n - 1, n);
    tree t;
    t.preorder(root);

    return 0;
}