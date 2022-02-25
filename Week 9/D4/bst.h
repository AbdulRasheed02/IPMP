#ifndef BST_H
#define BST_H
#include <iostream>
#include "tree.cpp"
using namespace std;

class bst : public tree
{
public:
    node *insert(node *root, int value);
    node *search(node *root, int value);
    node *maximum(node *root);
    node *minimum(node *root);
    // void *del(node *root, int value);
};

node *bst::insert(node *root, int value)
{
    if (root == NULL)
    {
        return new node(value);
    }
    if (root->value < value)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }

    return root;
}

node *bst::search(node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->value == value)
    {
        return root;
    }
    if (root->value < value)
    {
        return search(root->right, value);
    }
    return search(root->left, value);
}

node *bst::maximum(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

node *bst::minimum(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

#endif
