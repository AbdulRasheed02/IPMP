#include "linkedlist.cpp"
using namespace std;
bool checkPalindrome(linkedList::node *head, int length)
{
    linkedList::node *temp = head;
    int array[length];
    int i = 0, j = 0, k = length - 1;
    while (i < length)
    {
        array[i] = temp->data;
        i++;
        temp = temp->next;
    }
    while (j < k)
    {
        if (array[j] != array[k])
        {
            return false;
        }
        j++;
        k--;
    }
    return true;
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
    cout << "Given List is palindrome: " << checkPalindrome(list1.head, list1.listLength()) << endl;
    linkedList list2;
    list2.addNode(2);
    list2.addNode(5);
    list2.addNode(3);
    list2.addNode(3);
    list2.addNode(5);
    list2.addNode(2);
    list2.printList();
    cout << "Given List is palindrome: " << checkPalindrome(list2.head, list2.listLength()) << endl;
    linkedList list3;
    list3.addNode(2);
    list3.addNode(5);
    list3.addNode(3);
    list3.addNode(1);
    list3.addNode(5);
    list3.addNode(2);
    list3.printList();
    cout << "Given List is palindrome: " << checkPalindrome(list3.head, list3.listLength()) << endl;
    linkedList list4;
    list4.addNode(2);
    list4.addNode(5);
    list4.addNode(3);
    list4.addNode(4);
    list4.addNode(7);
    list4.addNode(3);
    list4.addNode(5);
    list4.addNode(2);
    list4.printList();
    cout << "Given List is palindrome: " << checkPalindrome(list4.head, list4.listLength()) << endl;
}