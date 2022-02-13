#include <iostream>
#include "tree.cpp"
#include <fstream>
ofstream fp1;
ifstream fp2;
using namespace std;
void serialise(node *root)
{
    if (root == NULL)
    {
        fp1 << -1 << " ";
        return;
    }
    fp1 << root->value << " ";
    serialise(root->left);
    serialise(root->right);
}
node *deserialise(node *root)
{
    int value;
    if (!(fp2 >> value) || value == -1)
    {
        // cout << "Hi";
        return NULL;
    }
    root = new node(value);
    // cout << root->value << " ";
    root->left = deserialise(root->left);
    root->right = deserialise(root->right);
    return root;
}
int main()
{
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    fp1.open("file.txt");
    serialise(root);
    fp1.close();

    fp2.open("file.txt");
    node *newRoot = deserialise(newRoot);
    fp2.close();

    tree t;
    t.levelOrder(root);
    cout << endl;
    t.levelOrder(newRoot);

    return 0;
}