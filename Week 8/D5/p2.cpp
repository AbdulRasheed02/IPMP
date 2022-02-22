#include <iostream>
#include "tree.cpp"
using namespace std;
node *inOrderPredecessor(node *root)
{
    node *pre = root->left;
    if (pre->right != NULL && pre->right != root)
    {
        pre = pre->right;
    }
    return pre;
}
void morris(node *root)
{
    node *current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->value << " ";
            current = current->right;
        }
        else
        {
            node *pre = inOrderPredecessor(current);
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                cout << current->value << " ";
                pre->right = NULL;
                current = current->right;
            }
        }
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    morris(root);
    cout << endl;
    tree t;
    t.inorder(root);
    return 0;
}