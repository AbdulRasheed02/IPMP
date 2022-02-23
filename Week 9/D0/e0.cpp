#include <iostream>
#include "bst.cpp"
using namespace std;
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
    cout << b.minimum(root)->value;
    return 0;
}