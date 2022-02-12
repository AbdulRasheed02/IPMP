#include <iostream>
#include "tree.cpp"
using namespace std;
bool checkIsomorphic(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->value == root2->value)
    {
        return ((checkIsomorphic(root1->left, root2->left) && checkIsomorphic(root1->right, root2->right)) || (checkIsomorphic(root1->left, root2->right) && checkIsomorphic(root1->right, root2->left)));
    }
    return false;
}
int main()
{
    node *root1 = new node(1);
    node *root2 = new node(1);

    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->left->right->left = new node(7);
    root1->left->right->right = new node(8);

    root2->left = new node(3);
    root2->right = new node(2);
    root2->right->left = new node(4);
    root2->right->right = new node(5);
    root2->left->right = new node(6);
    root2->right->right->left = new node(8);
    root2->right->right->right = new node(7);

    if (checkIsomorphic(root1, root2))
    {
        cout << "Isomorphic";
    }
    else
    {
        cout << "Not Isomorphic";
    }

    return 0;
}
