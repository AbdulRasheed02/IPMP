#include <iostream>
#include "heap.cpp"
using namespace std;
int main()
{
    heap h;
    h.add(5);
    h.add(8);
    h.add(2);
    h.add(9);
    h.add(11);
    h.add(1);
    h.add(7);
    h.add(4);
    cout << h.peek() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    cout << h.poll() << endl;
    return 0;
}