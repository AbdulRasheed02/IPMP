#include <iostream>
#include "bst.cpp"
using namespace std;
void swapNodes(node *root, node **first, node **middle, node **last, node **prev)
{
    if (root != NULL)
    {
        swapNodes(root->left, first, middle, last, prev);
        if (*prev != NULL && root->value < (*prev)->value)
        {
            if (*first == NULL)
            {
                *first = *prev;
                *middle = root;
            }
            else
            {
                *last = root;
            }
        }
        *prev = root;
        swapNodes(root->right, first, middle, last, prev);
    }
}
int main()
{
    bst b;
    node *root = new node(6);
    root->left = new node(10);
    root->right = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(12);
    root->right->left = new node(7);
    b.inorder(root);
    struct node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    cout << endl;
    swapNodes(root, &first, &middle, &last, &prev);
    if (first && last)
    {
        swap(first->value, last->value);
    }
    else if (first && middle)
    {
        swap(first->value, middle->value);
    }
    b.inorder(root);

    return 0;
}