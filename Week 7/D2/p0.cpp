#include <iostream>
#include "heap.cpp"
using namespace std;
void printCode(heapNode *top, string code)
{
    if ((!top))
    {
        return;
    }
    if (top->character != '$')
    {
        cout << top->character << " : " << code;
        return;
    }

    printCode(top->left, code + '0');
    printCode(top->right, code + '1');
}
int main()
{
    int n = 6;
    char a[n] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[n] = {5, 9, 12, 13, 16, 45};
    heap h;
    heapNode left, right, top;

    for (int i = 0; i < n; i++)
    {
        // cout << i << endl;
        h.add(a[i], freq[i], nullptr, nullptr);
    }
    // for (int i = 0; i < h.count(); i++)
    // {
    //     cout << h.arr[i].character;
    // }
    // cout << endl;
    // cout << h.poll().frequency << endl;
    // for (int i = 0; i < h.count(); i++)
    // {
    //     cout << h.arr[i].character;
    // }
    // cout << endl;
    // cout << h.poll().frequency << endl;
    // cout << h.poll().frequency << endl;
    // cout << h.poll().frequency << endl;
    // cout << h.poll().frequency << endl;
    // cout << h.poll().frequency << endl;

    while (h.count() != 1)
    {
        // cout << h.count() << endl;
        left = h.poll();
        right = h.poll();

        h.add('$', left.frequency + right.frequency, &left, &right);
    }
    // cout << h.peek().character << endl;
    // cout << h.poll().frequency << endl;
    top = h.peek();
    printCode(&top, "");

    return 0;
}