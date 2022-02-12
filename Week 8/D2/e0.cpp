#include <iostream>
#include "tree.cpp"
using namespace std;

void doubleTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *temp = root->left;
    root->left = new node(root->value);
    root->left->left = temp;

    doubleTree(root->left->left);
    doubleTree(root->right);
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    tree t;
    t.levelOrder(root);
    cout << endl;
    doubleTree(root);
    t.levelOrder(root);
    return 0;
}