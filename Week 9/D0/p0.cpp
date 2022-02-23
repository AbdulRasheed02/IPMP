#include <iostream>
#include "bst.cpp"
using namespace std;
int main()
{
    bst b;
    node *root = NULL;
    root = b.insert(root, 5);
    b.insert(root, 3);
    b.insert(root, 1);
    b.insert(root, 8);
    b.insert(root, 9);
    b.insert(root, 2);
    b.inorder(root);
    cout << endl;
    cout << b.maximum(root)->value << endl;
    cout << b.minimum(root)->value << endl;
    cout << b.search(root, 3)->left->value;
    return 0;
}