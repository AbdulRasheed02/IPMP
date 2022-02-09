#include <iostream>
#include "tree.cpp"
using namespace std;
bool checkSameTree(node *root1, node *root2)
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
        return (checkSameTree(root1->left, root2->left) && checkSameTree(root1->right, root2->right));
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

    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);

    if (checkSameTree(root1, root2))
    {
        cout << "Identical";
    }
    else
    {
        cout << "Not Identical";
    }

    return 0;
}
