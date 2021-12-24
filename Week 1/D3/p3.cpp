#include "linkedlist.h"
using namespace std;
void rotateList(linkedList *list, int k)
{
    if (k < 1)
    {
        list->printList();
        return;
    }
    else if (k >= list->listLength())
    {
        cout << "K is greater than or equal to list length";
        return;
    }
    linkedList::node *temp = list->head;
    int count = 1;
    while (count < k)
    {
        temp = temp->next;
        count++;
    }
    linkedList::node *temp2 = temp->next;
    temp->next = NULL;
    list->tail->next = list->head;
    list->head = temp2;
    list->printList();
}
int main()
{
    linkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);
    list.printList();
    rotateList(&list, 5);
}