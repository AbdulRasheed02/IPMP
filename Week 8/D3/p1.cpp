#include <iostream>
#include "tree.cpp"
using namespace std;
void increment(struct node *root, int difference)
{
    if (root->left != NULL)
    {
        root->left->value += difference;
        increment(root->left, difference);
    }
    else if (root->right != NULL)
    {
        root->right->value += difference;
        increment(root->right, difference);
    }
}

int nodeSum(struct node *root)
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
void applyChildrenSum(struct node *root)
{
    int childSum, difference;
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    applyChildrenSum(root->left);
    applyChildrenSum(root->right);
    difference = nodeSum(root) - (root->value);
    if (difference > 0)
    {
        root->value += difference;
    }
    else if (difference < 0)
    {
        increment(root, -difference);
    }
}
int main()
{
    tree t;
    node *root = new node(50);
    root->left = new node(7);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(1);
    root->right->right = new node(30);
    t.levelOrder(root);
    cout << endl;
    applyChildrenSum(root);
    t.levelOrder(root);

    return 0;
}