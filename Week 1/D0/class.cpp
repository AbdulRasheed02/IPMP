#include "linkedlist.cpp"
using namespace std;
int main()
{
    linkedList l1;
    l1.addNode(5);
    l1.addNode(7);
    l1.addNode(8);
    l1.addNode(9);
    l1.printList();
    l1.deleteNode();
    l1.deleteNode();
    l1.deleteNode();
    l1.printList();
    l1.deleteNode();
    l1.printList();
    l1.addNode(5);
    l1.addNode(7);
    l1.addNode(8);
    l1.addNode(9);
    l1.printList();
    cout << "Length: " << l1.listLength() << endl;
    cout << "8 Exists: " << l1.searchList(8) << endl;
    l1.deleteList();
    l1.printList();
}
