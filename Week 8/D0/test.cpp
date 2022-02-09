#include <iostream>
#include "tree.cpp"
using namespace std;
int main()
{
    tree t;
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    t.inorder(root);
    cout << endl;
    t.preorder(root);
    cout << endl;
    t.postorder(root);
    cout << endl;

    cout << t.getHeight(root) << endl;
    cout << t.getMaximumWidth(root) << endl;
    cout << t.getSize(root) << endl;
    cout << t.getDiameter(root) << endl;

    return 0;
}