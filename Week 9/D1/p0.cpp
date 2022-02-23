#include <iostream>
#include "bst.cpp"
using namespace std;
void kthElement(node *root, int k, int *current)
{

    if (root == NULL)
    {
        return;
    }
    kthElement(root->left, k, current);
    *current += 1;
    if (*current == k)
    {
        cout << root->value;
        return;
    }
    kthElement(root->right, k, current);
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
    b.inorder(root);
    cout << endl;
    int k = 5;
    int a = 0;
    int *current;
    current = &a;
    if (k > b.getSize(root))
    {
        cout << "Does not Exist";
    }
    else
    {
        kthElement(root, k, current);
    }

    return 0;
}