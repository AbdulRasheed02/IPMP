#include <iostream>
#include "tree.cpp"
using namespace std;
bool foundNum1 = false;
bool foundNum2 = false;
struct node *findLca(node *root, int num1, int num2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->value == num1)
    {
        foundNum1 = true;
        return root;
    }
    if (root->value == num2)
    {
        foundNum2 = true;
        return root;
    }
    node *left = findLca(root->left, num1, num2);
    node *right = findLca(root->right, num1, num2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL)
    {
        return right;
    }
    else
    {
        return left;
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    if (findLca(root, 4, 5) && foundNum1 && foundNum2)
    {
        cout << findLca(root, 4, 5)->value;
    }
    else
    {
        cout << "Element not in tree";
    }

    return 0;
}