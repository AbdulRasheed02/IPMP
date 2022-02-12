#include <iostream>
#include "tree.cpp"
#include <queue>
using namespace std;
bool nullNode = false;
bool completeTree;

void getComplete(node *root, int level)
{
    if (root == NULL)
    {
        nullNode = true;
        return;
    }
    if (level == 0)
    {
        if (nullNode)
        {
            completeTree = false;
        }
        return;
    }
    getComplete(root->left, level - 1);
    getComplete(root->right, level - 1);
}

void complete(node *root, int height)
{
    completeTree = true;
    for (int i = 0; i < height; i++)
    {
        getComplete(root, i);
        nullNode = false;
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    tree t;
    complete(root, t.getHeight(root));
    if (completeTree)
    {
        cout << "Complete Tree";
    }
    else
    {
        cout << "Not Complete Tree";
    }

    return 0;
}