#include "linkedlist.cpp"
using namespace std;
void mergeSorted(linkedList *list1, linkedList *list2)
{
    linkedList::node *temp1 = list1->head;
    linkedList::node *temp2 = list2->head;
    linkedList sortedList;

    while ((temp1 != NULL) && (temp2 != NULL))
    {
        if (temp1->data < temp2->data)
        {
            sortedList.addNode(temp1->data);

            temp1 = temp1->next;
        }
        else
        {
            sortedList.addNode(temp2->data);

            temp2 = temp2->next;
        }
    }

    if (temp1 == NULL)
    {

        while (temp2 != NULL)
        {

            sortedList.addNode(temp2->data);
            temp2 = temp2->next;
        }
    }

    if (temp2 == NULL)
    {
        while (temp1 != NULL)
        {
            sortedList.addNode(temp1->data);
            temp1 = temp1->next;
        }
    };
    cout << "Sorted List:" << endl;
    sortedList.printList();
    cout << endl;
}
int main()
{
    linkedList list1;
    list1.addNode(1);
    list1.addNode(4);
    list1.addNode(5);
    list1.addNode(7);
    list1.addNode(11);
    list1.addNode(15);
    list1.addNode(19);
    list1.printList();
    linkedList list2;
    list2.addNode(1);
    list2.addNode(2);
    list2.addNode(3);
    list2.addNode(5);
    list2.addNode(6);
    list2.addNode(30);
    list2.printList();
    mergeSorted(&list1, &list2);

    linkedList list3;
    list3.addNode(5);
    list3.addNode(10);
    list3.addNode(15);
    list3.printList();
    linkedList list4;
    list4.addNode(2);
    list4.addNode(3);
    list4.addNode(20);
    list4.printList();
    mergeSorted(&list3, &list4);
}