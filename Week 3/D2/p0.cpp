#include "linkedlist.cpp"
using namespace std;
linkedList::node *SortedMerge(linkedList::node *a, linkedList::node *b)
{
    linkedList::node *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}
void split(linkedList::node *head, linkedList::node **front, linkedList::node **back)
{
    linkedList::node *fast;
    linkedList::node *slow;
    slow = head;
    fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}
void mergeSort(linkedList::node **headptr)
{
    linkedList::node *head = *headptr;
    linkedList::node *a, *b;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headptr = SortedMerge(a, b);
}
int main()
{
    linkedList list1;
    list1.addNode(11);
    list1.addNode(5);
    list1.addNode(1);
    list1.addNode(6);
    list1.addNode(18);
    list1.addNode(13);
    list1.addNode(7);
    list1.printList();

    mergeSort(&list1.head);
    cout << "Sorted List:" << endl;
    list1.printList();
    cout << endl;

    linkedList list2;
    list2.addNode(2);
    list2.addNode(4);
    list2.addNode(3);
    list2.addNode(31);
    list2.addNode(13);
    list2.addNode(8);
    list2.printList();
    mergeSort(&list2.head);
    cout << "Sorted List:" << endl;
    list2.printList();
    cout << endl;
}