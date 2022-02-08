#ifndef LIST_H2_
#define LIST_H2_
#include <iostream>
using namespace std;

class maxHeap
{
public:
    const static int maxCapacity = 30;
    int arr[maxCapacity];
    int size = 0;

    void heapifyUp();
    void heapifyDown();
    void add(int value);
    int peek();
    int poll();

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
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    int count()
    {
        return size - 1;
    }
};

void maxHeap::heapifyUp()
{
    int index = size - 1;
    while (checkParentExists(index) && arr[parentIndex(index)] < arr[index])
    {
        swapNode(index, parentIndex(index));
        index = parentIndex(index);
    }
}
void maxHeap::heapifyDown()
{
    int index = 0;
    while (checkLeftChildExists(index))
    {
        int smallChildIndex = leftChildIndex(index);
        if (checkRightChildExists(index) && (arr[rightChildIndex(index)] > arr[smallChildIndex]))
        {
            smallChildIndex = rightChildIndex(index);
        }
        if (arr[index] < arr[smallChildIndex])
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
void maxHeap::add(int value)
{
    arr[size] = value;
    size++;
    heapifyUp();
}
int maxHeap::peek()
{
    if (size == 0)
    {
        cout << "Max Heap is Empty" << endl;
        return -1;
    }
    else
    {
        return arr[0];
    }
}
int maxHeap::poll()
{
    if (size == 0)
    {
        cout << "Heap is Empty ";
        return -1;
    }
    else
    {
        int data = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown();
        return data;
    }
}
#endif