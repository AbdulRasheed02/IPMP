#include <iostream>
#include "tree.cpp"
using namespace std;
int childSum(node *root)
{
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->value;
    }
    if (root->right != NULL)
    {
        sum += root->right->value;
    }
    return sum;
}
bool checkNodeSum(node *root)
{
    int nodeSum;
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        nodeSum = root->value;
    }
    else
    {
        nodeSum = childSum(root);
    }

    if (root->value == nodeSum && checkNodeSum(root->left) && checkNodeSum(root->right))
    {
        return true;
    }
    return false;
}
int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(2);
    if (checkNodeSum(root))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}