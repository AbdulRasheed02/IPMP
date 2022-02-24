#include <iostream>
#include "tree.cpp"
using namespace std;
void dll(node *root, node **head, node **tail)
{
    if (root == NULL)
    {
        return;
    }
    dll(root->left, head, tail);
    if (*head == NULL)
    {
        *head = root;
    }
    root->left = *tail;
    if (*tail != NULL)
    {
        (*tail)->right = root;
    }
    *tail = root;
    dll(root->right, head, tail);
}
int main()
{
    tree t;
    node *root = new node(10);
    root->left = new node(12);
    root->right = new node(15);
    root->left->left = new node(25);
    root->left->right = new node(30);
    root->right->left = new node(36);
    // t.inorder(root);
    // cout << endl;

    node *head, *tail;
    head = NULL;
    tail = NULL;
    dll(root, &head, &tail);
    // cout << head->value;
    // cout << "Hello";
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->right;
    }
    cout << endl;
    temp = tail;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->left;
    }

    return 0;
}