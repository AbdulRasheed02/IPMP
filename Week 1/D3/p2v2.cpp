#include "linkedlist.cpp"
#include "string.h"
using namespace std;

linkedList::node *addLinkedList(linkedList::node *head1, linkedList::node *head2, int *carry)
{
    if (head1 == NULL)
    {
        return NULL;
    }
    int sum;
    linkedList::node *result = new linkedList::node();
    result->next = addLinkedList(head1->next, head2->next, carry);
    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;
    result->data = sum;
    return result;
}
void addCarry(linkedList::node *head, linkedList::node *current, int *carry, linkedList::node **result)
{
    int sum;
    if (head != current)
    {
        addCarry(head->next, current, carry, result);

        sum = head->data + *carry;
        *carry = sum / 10;
        sum %= 10;

        linkedList::node *temp;
        temp->data = *carry;
        temp->next = *result;
        *result = temp;
    }
}
void add(linkedList::node *head1, linkedList::node *head2, linkedList::node **result, linkedList *list1, linkedList *list2)
{
    int carry = 0;
    if (head1 == NULL)
    {
        cout << "Sum:";
        list2->printList();
        return;
    }
    else if (head2 == NULL)
    {
        cout << "Sum:";
        list1->printList();
        return;
    }
    if (list1->listLength() == list2->listLength())
    {
        *result = addLinkedList(head1, head2, &carry);
    }
    else
    {
        if (list1->listLength() < list2->listLength())
        {
            linkedList::node *temp;
            temp = list1->head;
            list1->head = list2->head;
            list2->head = temp;
        }
        int diff = list1->listLength() - list2->listLength();
        linkedList::node *temp = head1;
        for (int i = 0; i < diff; i++)
        {
            temp = temp->next;
        }
        *result = addLinkedList(temp, head2, &carry);
        addCarry(head1, temp, &carry, result);
    }
    if (carry)
    {
        linkedList::node *temp;
        temp->data = carry;
        temp->next = *result;
        *result = temp;
    }
}
int main()
{
    linkedList list1;
    list1.addNode(9);
    list1.addNode(9);
    list1.addNode(9);
    list1.printList();
    linkedList list2;
    list2.addNode(1);
    list2.addNode(8);
    list2.printList();

    linkedList sum;
    linkedList::node *result = sum.head;

    add(list1.head, list2.head, &result, &list1, &list2);
    sum.printList();

    return 0;
}