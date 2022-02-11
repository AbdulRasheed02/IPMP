#include "tree.cpp"
#include <iostream>
#include <map>
using namespace std;
void printLeft(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    cout << root->value << " ";
    if (root->left == NULL && root->right != NULL)
    {
        printLeft(root->right);
    }
    else
    {
        printLeft(root->left);
    }
}
void printLeaf(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->value << " ";
        return;
    }
    printLeaf(root->left);
    printLeaf(root->right);
}
void printRight(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right == NULL && root->left != NULL)
    {
        printRight(root->left);
    }
    else
    {
        printRight(root->right);
    }
    cout << root->value << " ";
}
void boundary(node *root)
{
    printLeft(root);
    // cout << endl;
    printLeaf(root);
    // cout << endl;
    printRight(root->right);
}
int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->right->left = new node(6);
    root->left->right->left->right = new node(7);
    root->right = new node(5);
    root->right->right = new node(8);
    boundary(root);

    return 0;
}