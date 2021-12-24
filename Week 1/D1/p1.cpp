#include "linkedlist.cpp"
using namespace std;
int middle(linkedList list)
{
    int length = list.listLength();
    int middle = (length / 2) + 1;
    int count = 1;
    linkedList::node *temp = list.head;
    while (count < middle)
    {
        temp = temp->next;
        count++;
    }
    return temp->data;
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
    cout << "Middle of List: " << middle(list1) << endl;
    linkedList list2;
    list2.addNode(2);
    list2.addNode(5);
    list2.addNode(3);
    list2.addNode(9);
    list2.addNode(5);
    list2.addNode(8);
    list2.printList();
    cout << "Middle of List: " << middle(list2) << endl;
}
