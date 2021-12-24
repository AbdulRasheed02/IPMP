#include "linkedlist.cpp"
using namespace std;
void removeLoop(linkedList *list, linkedList::node *slow)
{
    linkedList::node *temp = slow->next;
    int count = 1;
    while (temp != slow)
    {
        temp = temp->next;
        count++;
    }
    cout << "Length of the loop:" << count << endl;

    linkedList::node *head1 = list->head, *temp2 = list->head;

    int count2 = 0;
    while (count2 < count)
    {
        temp2 = temp2->next;
        count2++;
    }
    while (temp2 != head1)
    {
        temp2 = temp2->next;
        head1 = head1->next;
    }
    while (temp2->next != head1)
    {
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    cout << "After Removing Loop:\n";
    list->printList();
}
void detectAndRemoveLoop(linkedList *list)
{
    linkedList::node *slow;
    linkedList::node *fast;
    slow = fast = list->head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Loop Exists\n";
            removeLoop(list, slow);
            return;
        }
    }
    cout << "Loop does not exist\n";
}
int main()
{
    linkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.tail->next = list.head->next;
    detectAndRemoveLoop(&list);
    cout << endl;

    linkedList list2;
    list2.addNode(1);
    list2.addNode(2);
    list2.addNode(3);
    list2.addNode(4);
    list2.addNode(5);
    detectAndRemoveLoop(&list2);
}