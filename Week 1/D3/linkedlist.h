#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <string.h>
using namespace std;

class linkedList
{
public:
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head = NULL;
    struct node *tail = NULL;
    void addNode(int data);
    void deleteNode();
    void deleteList();
    void printList();
    bool searchList(int data);
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
void linkedList::deleteNode()
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
    }
    else if (head->next == NULL)
    {
        head = NULL;
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        temp = temp->next;
        tail->next = NULL;
        delete (temp);
    }
}
void linkedList::deleteList()
{
    struct node *current = head;
    struct node *next;
    while (current != NULL)
    {
        next = current->next;
        delete (current);
        current = next;
    }
    head = NULL;
    tail = NULL;
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
bool linkedList::searchList(int data)
{

    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
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
#endif