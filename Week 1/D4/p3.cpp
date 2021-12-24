#include <iostream>
using namespace std;
class linkedList
{
public:
    struct node
    {
        int data;
        struct node *next, *arbit;
    };
    struct node *head = NULL;
    struct node *tail = NULL;
    void addNode(int data);
    void printList();
    void printArbit(int length);
    int listLength();
};

void linkedList::addNode(int data)
{
    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void linkedList::printList()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
    }
    else
    {
        struct node *temp = head;
        cout << "Linked List:" << endl;
        while (temp != NULL)
        {
            cout << temp->data << ",";
            temp = temp->next;
        }
        cout << endl;
    }
}

void linkedList::printArbit(int length)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
    }
    else
    {
        struct node *temp = head;
        cout << "Arbit Linked List:" << endl;
        int i = 0;
        while (i < length)
        {
            cout << temp->data << ",";
            temp = temp->arbit;
            i++;
        }
        cout << endl;
    }
}
int linkedList::listLength()
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void clone(linkedList::node *head)
{
    linkedList clone;
    linkedList::node *temp = head;
    while (temp != NULL)
    {
        clone.addNode(temp->data);
        temp = temp->next;
    }
    cout << "\nCloned:"
         << "\n";
    clone.printList();
    temp = head;

    linkedList::node *temp1 = head;
    linkedList::node *temp2 = head;
    linkedList::node *ctemp1 = clone.head;
    linkedList::node *ctemp2 = clone.head;

    while (temp1 != NULL)
    {
        int position = 1;
        temp2 = head;
        ctemp2 = clone.head;
        while (temp2 != temp1->arbit)
        {
            position++;
            temp2 = temp2->next;
        }
        //cout << position << ",";
        int i = 0;
        for (i = 0; i < position - 1; i++)
        {
            ctemp2 = ctemp2->next;
        }
        //cout << i + 1 << ",";
        ctemp1->arbit = ctemp2;
        ctemp1 = ctemp1->next;
        temp1 = temp1->next;
    }

    int length = clone.listLength();
    clone.printArbit(length);
}
int main()
{
    linkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    list.head->arbit = list.head->next->next;
    list.head->next->arbit = list.head;
    list.head->next->next->arbit = list.head->next->next->next->next;
    list.head->next->next->next->arbit = list.head->next->next;
    list.head->next->next->next->next->arbit = list.head->next;

    list.printList();
    int length = list.listLength();
    list.printArbit(length);
    clone(list.head);
}