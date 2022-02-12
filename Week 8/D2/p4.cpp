#include <iostream>
#include "tree.cpp"
using namespace std;
bool checkFoldable(struct node *root, struct node *root2)
{
    if (root == NULL && root2 == NULL)
    {
        return true;
    }
    if (root == NULL || root2 == NULL)
    {
        return false;
    }
    return (checkFoldable(root->left, root2->right) && checkFoldable(root->right, root2->left));
}
int main()
{

    node *root = new node(10);
    root->left = new node(7);
    root->right = new node(15);
    root->left->right = new node(9);
    root->right->left = new node(11);

    if (root == NULL || checkFoldable(root->left, root->right))
    {
        cout << "Foldable";
    }
    else
    {
        cout << "Not Foldable";
    }

    return 0;
}