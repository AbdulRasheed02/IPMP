#include "linkedlist.cpp"
using namespace std;
void printReverse(linkedList::node *head)
{
    if (head == NULL)
    {
        return;
    }
    printReverse(head->next);
    cout << head->data << ",";
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
    printReverse(list1.head);
    cout << endl;
    linkedList list2;
    list2.addNode(2);
    list2.addNode(5);
    list2.addNode(3);
    list2.addNode(9);
    list2.addNode(5);
    list2.addNode(8);
    list2.printList();
    printReverse(list2.head);
    cout << endl;
}
