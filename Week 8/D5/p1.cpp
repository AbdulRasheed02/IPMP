#include <iostream>
#include "tree.cpp"
using namespace std;
int mat[100][100];
void ancestor(node *root, int i)
{
    if (root == NULL)
    {
        return;
    }
    ancestor(root->left, i);
    ancestor(root->right, i);
    if (root->left != NULL)
    {
        mat[i][root->left->value] = 1;
        ancestor(root->left, root->left->value);
    }
    if (root->right != NULL)
    {
        mat[i][root->right->value] = 1;
        ancestor(root->right, root->right->value);
    }
}
void buildAncestor(node *root)
{
    tree t;
    int size = t.getSize(root);
    ancestor(root, root->value);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(0);
    root->left->right = new node(4);
    root->right->left = new node(3);
    buildAncestor(root);
    return 0;
}