#include <iostream>
#include "tree.h"
using namespace std;
void inorderSuccessor(node *root, node *&previous)
{
    if (root == NULL)
    {
        return;
    }
    inorderSuccessor(root->left, previous);
    if (previous == NULL)
    {
        previous = root;
    }
    else
    {
        previous->next = root;
        previous = root;
    }
    inorderSuccessor(root->right, previous);
}
int main()
{
    node *previous = NULL;
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(12);
    root->left->left = new node(3);
    inorderSuccessor(root, previous);
    tree t;
    t.inorder(root);
    return 0;
}