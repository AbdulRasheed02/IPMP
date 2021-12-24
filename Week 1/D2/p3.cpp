#include "linkedlist.cpp"
#include <unordered_map>
using namespace std;
void unionIntersection(linkedList::node *head1, linkedList::node *head2)
{
    unordered_map<int, int> umap;
    linkedList listunion, intersection;
    linkedList::node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL)
    {
        umap[temp1->data]++;
        listunion.addNode(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        if (umap[temp2->data] == 1)
        {
            intersection.addNode(temp2->data);
        }
        else
        {
            listunion.addNode(temp2->data);
        }
        temp2 = temp2->next;
    }
    cout << "\nUnion of Two Lists:" << endl;
    listunion.printList();
    cout << "Intersection of Two Lists:" << endl;
    intersection.printList();
}
int main()
{
    linkedList list1;
    list1.addNode(2);
    list1.addNode(5);
    list1.addNode(3);
    list1.addNode(9);
    list1.addNode(13);
    list1.addNode(1);
    list1.addNode(4);
    list1.printList();
    linkedList list2;
    list2.addNode(1);
    list2.addNode(2);
    list2.addNode(3);
    list2.addNode(4);
    list2.addNode(5);
    list2.addNode(10);
    list2.printList();
    unionIntersection(list1.head, list2.head);

    cout << endl;
    linkedList list3;
    list3.addNode(10);
    list3.addNode(15);
    list3.addNode(4);
    list3.addNode(20);
    list3.printList();
    linkedList list4;
    list4.addNode(8);
    list4.addNode(4);
    list4.addNode(2);
    list4.addNode(10);
    list4.printList();
    unionIntersection(list3.head, list4.head);

    return 0;
}