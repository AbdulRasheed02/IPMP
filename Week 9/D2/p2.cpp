#include <iostream>
#include "bst.cpp"
using namespace std;
node *dllToBst(node **head, int n)
{
    if (n <= 0)
    {
        return NULL;
    }
    node *left = dllToBst(head, n / 2);
    node *root = *head;
    root->left = left;
    *head = (*head)->right;
    root->right = dllToBst(head, n - (n / 2) - 1);
    return root;
}
int main()
{
    node *current, *prev;
    current = prev = NULL;
    node *head = current = new node(7);
    current->left = prev;
    prev = current;
    head->right = current = new node(6);
    current->left = prev;
    prev = current;
    head->right->right = current = new node(5);
    current->left = prev;
    prev = current;
    head->right->right->right = current = new node(4);
    current->left = prev;
    prev = current;
    head->right->right->right->right = current = new node(3);
    current->left = prev;
    prev = current;
    head->right->right->right->right->right = current = new node(2);
    current->left = prev;
    prev = current;
    head->right->right->right->right->right->right = current = new node(1);
    current->right = NULL;
    current->left = prev;
    prev = current;

    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        cout << temp->value << " ";
        temp = temp->right;
    }
    cout << endl;
    cout << count;
    cout << endl;
    temp = current;
    // while (temp != NULL)
    // {
    //     cout << temp->value << " ";
    //     temp = temp->left;
    // }
    // cout << endl;

    node *root = dllToBst(&head, count);
    tree t;
    t.inorder(root);

    return 0;
}