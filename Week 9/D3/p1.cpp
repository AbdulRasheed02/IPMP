#include <iostream>
#include "linkedlist.h"
#include "bst.cpp"
using namespace std;
node *llToBst(linkedList::node **head, int n)
{
    if (n <= 0)
    {
        return NULL;
    }
    node *left = llToBst(head, n / 2);
    node *root = new node((*head)->data);
    root->left = left;
    (*head) = (*head)->next;
    root->right = llToBst(head, n - (n / 2) - 1);
    return root;
}
int main()
{
    linkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    ll.addNode(4);
    ll.addNode(5);
    ll.addNode(6);
    ll.addNode(7);
    node *root = llToBst(&ll.head, ll.listLength());
    tree t;
    t.levelOrder(root);
    return 0;
}