#include <iostream>
#include "bst.cpp"
using namespace std;
node *removeOutsideRange(node *root, int low, int high)
{
    if (root == NULL)
    {
        return NULL;
    }
    root->left = removeOutsideRange(root->left, low, high);
    root->right = removeOutsideRange(root->right, low, high);
    if (root->value < low)
    {
        node *temp = root->right;
        delete (root);
        return temp;
    }
    if (root->value > high)
    {
        node *temp = root->left;
        delete (root);
        return temp;
    }
    return root;
}
int main()
{
    bst b;
    node *root = NULL;
    root = b.insert(root, 6);
    b.insert(root, -13);
    b.insert(root, 14);
    b.insert(root, -8);
    b.insert(root, 15);
    b.insert(root, 13);
    b.insert(root, 7);
    b.inorder(root);
    cout << endl;
    removeOutsideRange(root, -10, 13);
    b.inorder(root);
    return 0;
}