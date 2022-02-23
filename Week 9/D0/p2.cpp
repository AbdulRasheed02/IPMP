#include <iostream>
#include "bst.cpp"
using namespace std;
bool checkBST(node *root, node *&prev)
{
    if (root)
    {
        if (checkBST(root->left, prev) == false)
        {
            return false;
        }
        if (prev != NULL && root->value <= prev->value)
        {
            return false;
        }
        prev = root;
        return checkBST(root->right, prev);
    }
    return true;
}
int main()
{
    bst b;
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(4);
    node *prev = NULL;
    cout << boolalpha << checkBST(root, prev);
    return 0;
}