#include <iostream>
#include "tree.cpp"
using namespace std;
int preorderIndex = 0;
node *buildTree(int preorder[], char preorderLN[], int n)
{
    if (preorderIndex == n)
    {
        return;
    }
    node *root = new node(preorder[preorderIndex]);
    preorderIndex++;
    if (preorderLN[preorderIndex - 1] == 'L')
    {
        return root;
    }
    root->left = buildTree(preorder, preorderLN, n);
    root->right = buildTree(preorder, preorderLN, n);
    return root;
}
int main()
{
    int n = 5;
    int preorder[n] = {10, 30, 20, 5, 15};
    char preorderLN[n] = {'N', 'N', 'L', 'L', 'L'};
    node *root = buildTree(preorder, preorderLN, n);
    tree t;
    t.preorder(root);

    return 0;
}