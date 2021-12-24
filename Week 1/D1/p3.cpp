#include "linkedlist.cpp"
using namespace std;
void reverse(linkedList *list)
{
    linkedList::node *temp, *current, *previous, *nextptr;
    temp = list->head;
    current = list->head;
    previous = nextptr = NULL;
    while (current != NULL)
    {
        nextptr = current->next;
        current->next = previous;
        previous = current;
        current = nextptr;
    }
    list->tail = temp;
    list->head = previous;
}
int main()
{
    linkedList list1;
    list1.addNode(2);
    list1.addNode(5);
    list1.addNode(3);
    list1.addNode(9);
    list1.addNode(5);
    list1.addNode(8);
    list1.addNode(11);
    list1.printList();
    reverse(&list1);
    cout << list1.head->data;
    list1.printList();
    linkedList list2;
    list2.addNode(2);
    list2.addNode(5);
    list2.addNode(3);
    list2.addNode(9);
    list2.addNode(5);
    list2.addNode(8);
    list2.printList();
    reverse(&list2);
    list2.printList();
    cout << endl;
}