#include <iostream>
#include "bst.cpp"
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
node *mergeLL(node *head1, node *head2)
{
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }

    if (head1->value > head2->value)
    {
        node *temp = head1;
        head1 = head2;
        head2 = temp;
    }

    node *cur1 = head1, *next1 = head1->right;
    node *cur2 = head2, *next2 = head2->right;
    while (next1 != NULL && cur2 != NULL)
    {
        if (cur2->value >= cur1->value && cur2->value <= next1->value)
        {
            next2 = cur2->right;
            cur1->right = cur2;
            cur2->right = next1;
            cur1 = cur2;
            cur2 = next2;
        }
        else
        {
            if (next1->right)
            {
                cur1 = next1;
                next1 = cur1->right;
            }
            else
            {
                next1->right = cur2;
                return head1;
            }
        }
    }
    return head1;
}
node *llToBst(node **head, int n)
{
    if (n <= 0)
    {
        return NULL;
    }
    node *left = llToBst(head, n / 2);
    node *root = new node((*head)->value);
    root->left = left;
    (*head) = (*head)->right;
    root->right = llToBst(head, n - (n / 2) - 1);
    return root;
}
int main()
{
    tree t;

    node *root1 = new node(100);
    root1->left = new node(50);
    root1->right = new node(300);
    root1->left->left = new node(20);
    root1->left->right = new node(70);

    node *root2 = new node(80);
    root2->left = new node(40);
    root2->right = new node(120);

    node *head1, *tail1;
    head1 = NULL;
    tail1 = NULL;
    dll(root1, &head1, &tail1);

    node *head2, *tail2;
    head2 = NULL;
    tail2 = NULL;
    dll(root2, &head2, &tail2);

    node *temp = head1;
    // while (temp != NULL)
    // {
    //     cout << temp->value << " ";
    //     temp = temp->right;
    // }
    // cout << endl;

    // temp = head2;
    // while (temp != NULL)
    // {
    //     cout << temp->value << " ";
    //     temp = temp->right;
    // }
    // cout << endl;

    node *head = mergeLL(head1, head2);
    int count;
    temp = head;
    while (temp != NULL)
    {
        count++;
        // cout << temp->value << " ";
        temp = temp->right;
    }

    node *root = llToBst(&head, count);
    t.inorder(root);

    return 0;
}