#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *left, *right, *next;
    node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
        // For P2
        next = NULL;
    }
};

class tree
{
public:
    int getSize(node *root);
    int getHeight(node *root);
    int getDiameter(node *root);
    int getMaximumWidth(node *root);
    void inorder(node *root);
    void preorder(node *root);
    void postorder(node *root);
};

int tree::getSize(node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

int tree::getHeight(node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
};

int tree::getDiameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int currentDiamter = getHeight(root->left) + getHeight(root->right) + 1;
    return max(currentDiamter, max(getDiameter(root->left), getDiameter(root->right)));
}

int getWidth(node *root, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    if (level == 1)
    {
        return 1;
    }
    else if (level > 1)
    {
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
    }
    return 0;
}

int tree::getMaximumWidth(node *root)
{
    int maxWidth = 0;
    int width = 0;
    int height = getHeight(root);
    for (int i = 1; i <= height; i++)
    {
        width = getWidth(root, i);
        maxWidth = max(maxWidth, width);
    }
    return maxWidth;
}

void tree::inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void tree::preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void tree::postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

#endif
