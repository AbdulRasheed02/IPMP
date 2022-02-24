#include <iostream>
#include "tree.cpp"
using namespace std;
node *trimpath(node *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->left = trimpath(root->left, k - root->value);
    root->right = trimpath(root->right, k - root->value);
    if (root->left == NULL && root->right == NULL)
    {
        if (root->value < k)
        {
            free(root);
            return NULL;
        }
    }
    return root;
}
int main()
{
    tree t;
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(12);
    root->right->right->left = new node(10);
    root->right->right->left->right = new node(11);
    root->left->left->right->left = new node(13);
    root->left->left->right->right = new node(14);
    root->left->left->right->right->left = new node(15);
    t.inorder(root);
    cout << endl;
    int k = 45;
    root = trimpath(root, k);
    t.inorder(root);
    return 0;
}