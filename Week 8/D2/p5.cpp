#include <iostream>
#include "tree.cpp"
using namespace std;
void mirror(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    swap(root->left, root->right);
    mirror(root->right);
    mirror(root->left);
}
int main()
{
    tree t;
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    t.levelOrder(root);
    cout << endl;
    mirror(root);
    t.levelOrder(root);

    return 0;
}