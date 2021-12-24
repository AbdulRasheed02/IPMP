#include "linkedlist.cpp"
#include "string.h"
using namespace std;
void addLinkedList(linkedList *list1, linkedList *list2)
{
    linkedList::node *temp1 = list1->head;
    linkedList::node *temp2 = list2->head;
    string num1 = "";
    string num2 = "";
    while (temp1 != NULL)
    {
        num1 = num1 + char(temp1->data + '0');
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        num2 = num2 + char(temp2->data + '0');
        temp2 = temp2->next;
    }

    int value1 = stoi(num1);
    int value2 = stoi(num2);
    int sum = value1 + value2;
    string sm = to_string(sum);
    linkedList output;
    for (int i = 0; i < sm.length(); i++)
    {
        output.addNode((sm[i]) - '0');
    }
    output.printList();
}

int main()
{
    linkedList list1;
    list1.addNode(1);
    list1.addNode(4);
    list1.addNode(3);
    list1.addNode(6);
    list1.printList();
    linkedList list2;
    list2.addNode(4);
    list2.addNode(2);
    list2.addNode(8);
    list2.printList();
    addLinkedList(&list1, &list2);

    return 0;
}