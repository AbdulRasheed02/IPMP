#include "linkedlist.cpp"
#include <unordered_map>
using namespace std;
void triplet(linkedList::node *head1, linkedList::node *head2, linkedList::node *head3, int sum)
{

    linkedList::node *temp1 = head1, *temp2 = head2, *temp3 = head3;
    unordered_map<int, int> umap;
    while (temp1 != NULL)
    {

        umap[temp1->data]++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        temp3 = head3;
        while (temp3 != NULL)
        {
            if (umap[sum - (temp2->data + temp3->data)] > 0)
            {
                cout << "\nTriplet Exists:\n";
                cout << sum - (temp2->data + temp3->data) << ",";
                cout << temp2->data << ",";
                cout << temp3->data << "," << endl;
                return;
            }
            temp3 = temp3->next;
        }
        temp2 = temp2->next;
    }
    cout << "Triplet does not exist";
}

int main()
{
    linkedList list1;
    list1.addNode(12);
    list1.addNode(6);
    list1.addNode(29);
    list1.printList();

    linkedList list2;
    list2.addNode(23);
    list2.addNode(5);
    list2.addNode(8);
    list2.printList();

    linkedList list3;
    list3.addNode(90);
    list3.addNode(20);
    list3.addNode(59);
    list3.printList();

    int sum = 104;

    triplet(list1.head, list2.head, list3.head, sum);
}