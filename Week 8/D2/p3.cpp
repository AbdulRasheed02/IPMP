#include <iostream>
#include "tree.cpp"
using namespace std;
tree t;
bool checkBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftHeight = t.getHeight(root->left);
    int rightHeight = t.getHeight(root->right);
    if ((leftHeight - rightHeight <= 1 && rightHeight - leftHeight <= 1) && checkBalanced(root->left) && checkBalanced(root->right))
    {
        return true;
    }
    return false;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    // root->left->left->left = new node(8);

    if (checkBalanced(root))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}
