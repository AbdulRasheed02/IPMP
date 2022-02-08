#ifndef LIST_H_
#define LIST_H_
#include <iostream>
using namespace std;

class heapNode
{
public:
    char character;
    int frequency;
    heapNode *left, *right;
};

class heap
{
public:
    const static int maxCapacity = 50;
    heapNode arr[maxCapacity];
    int size = 0;

    void heapifyUp();
    void heapifyDown();
    void add(char c, int freq, heapNode *leftptr, heapNode *rightptr);
    heapNode peek();
    heapNode poll();

    bool checkLeftChildExists(int index)
    {
        return (2 * index + 1) < size;
    }
    bool checkRightChildExists(int index)
    {
        return (2 * index + 2) < size;
    }
    bool checkParentExists(int index)
    {
        return (index - 1) / 2 >= 0;
    }
    int leftChildIndex(int index)
    {
        return 2 * index + 1;
    }
    int rightChildIndex(int index)
    {
        return 2 * index + 2;
    }
    int parentIndex(int index)
    {
        return (index - 1) / 2;
    }
    void swapNode(int index1, int index2)
    {
        heapNode temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    int count()
    {
        return size;
    }
};

void heap::heapifyUp()
{
    int index = size - 1;
    while (checkParentExists(index) && arr[parentIndex(index)].frequency > arr[index].frequency)
    {
        swapNode(index, parentIndex(index));
        index = parentIndex(index);
    }
}
void heap::heapifyDown()
{
    int index = 0;
    while (checkLeftChildExists(index))
    {
        int smallChildIndex = leftChildIndex(index);
        if (checkRightChildExists(index) && (arr[rightChildIndex(index)].frequency < arr[smallChildIndex].frequency))
        {
            smallChildIndex = rightChildIndex(index);
        }
        if (arr[index].frequency < arr[smallChildIndex].frequency)
        {
            break;
        }
        else
        {
            swapNode(index, smallChildIndex);
        }
        index = smallChildIndex;
    }
}
void heap::add(char c, int freq, heapNode *leftptr, heapNode *rightptr)
{
    arr[size].character = c;
    arr[size].frequency = freq;
    arr[size].left = leftptr;
    arr[size].right = rightptr;
    size++;
    heapifyUp();
}
heapNode heap::peek()
{
    if (size == 0)
    {
        cout << "Heap is Empty";
        heapNode emptyNode;
        return emptyNode;
    }
    else
    {
        return arr[0];
    }
}
heapNode heap::poll()
{
    if (size == 0)
    {
        cout << "Heap is Empty ";
        heapNode emptyNode;
        return emptyNode;
    }
    else
    {
        heapNode data = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown();
        return data;
    }
}
#endif