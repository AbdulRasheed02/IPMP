#include <iostream>
#include "bst.cpp"
using namespace std;
node *findLca(node *root, int n1, int n2)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->value > n1 && root->value > n2)
    {
        return findLca(root->left, n1, n2);
    }
    if (root->value < n1 && root->value < n2)
    {
        return findLca(root->right, n1, n2);
    }
    return root;
}
int main()
{
    bst b;
    node *root = NULL;
    root = b.insert(root, 20);
    b.insert(root, 8);
    b.insert(root, 22);
    b.insert(root, 4);
    b.insert(root, 12);
    b.insert(root, 10);
    b.insert(root, 14);
    // b.levelOrder(root);

    int n1 = 10;
    int n2 = 14;
    if (b.search(root, n1) && b.search(root, n1))
    {
        cout << findLca(root, 10, 14)->value << endl;
    }
    else
    {
        cout << "Not Present" << endl;
    }
    n1 = 9;
    n2 = 22;
    if (b.search(root, n1) && b.search(root, n1))
    {
        cout << findLca(root, 10, 14)->value << endl;
    }
    else
    {
        cout << "Not Present";
    }

    return 0;
}