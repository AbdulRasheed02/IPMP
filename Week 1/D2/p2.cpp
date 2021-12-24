#include "linkedlist.cpp"
#include <unordered_map>
using namespace std;
void intersection(linkedList::node *head1, linkedList::node *head2)
{
    linkedList::node *temp = head1;
    linkedList::node *temp2 = head2;
    unordered_map<linkedList::node *, int> umap;
    while (temp != NULL)
    {
        umap[temp]++;
        temp = temp->next;
    }
    while (temp2 != NULL)
    {
        if (umap[temp2] > 0)
        {
            cout << "Intrersection at: " << temp2->data << endl;
            return;
        }
        temp2 = temp2->next;
    }
    cout << "No Intrersection" << endl;
}
int main()
{
    linkedList list1;
    list1.addNode(2);
    list1.addNode(5);
    list1.addNode(3);
    list1.addNode(9);
    list1.addNode(3);
    list1.addNode(5);
    list1.addNode(2);
    list1.printList();
    linkedList list2;
    list2.addNode(1);
    list2.addNode(2);
    list2.addNode(3);
    list2.addNode(4);
    list2.addNode(5);
    list2.head->next->next->next->next->next = list1.head->next->next->next;
    list2.printList();
    intersection(list1.head, list2.head);

    linkedList list3;
    list3.addNode(1);
    list3.addNode(2);
    list3.addNode(3);
    list3.addNode(4);
    list3.addNode(5);
    list3.addNode(6);
    list3.printList();
    linkedList list4;
    list4.addNode(11);
    list4.addNode(12);
    list4.addNode(13);
    list4.addNode(14);
    list4.addNode(15);
    list4.head->next->next->next->next->next = list3.head->next->next->next;
    list4.printList();
    intersection(list3.head, list4.head);
}