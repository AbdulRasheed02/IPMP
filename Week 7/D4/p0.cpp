#include <iostream>
#include "heap.cpp"
#include "maxHeap.cpp"
using namespace std;
heap minhp;
maxHeap maxhp;
void addToHeap(int number)
{
    if (maxhp.count() == -1 || number < maxhp.peek())
    {
        maxhp.add(number);
    }
    else
    {
        minhp.add(number);
    }
}
void balanceHeaps()
{
    if (maxhp.count() > minhp.count())
    {
        if (maxhp.count() - minhp.count() == 2)
        {
            minhp.add(maxhp.poll());
        }
    }
    else
    {
        if (minhp.count() - maxhp.count() == 2)
        {
            maxhp.add(minhp.poll());
        }
    }
}
double findMedian()
{
    double median;
    // cout << "Size " << minhp.count() + 1 << " " << maxhp.count() + 1 << endl;
    // cout << minhp.peek() << " " << maxhp.peek() << endl;
    if (minhp.count() == maxhp.count())
    {
        return ((double)(minhp.peek() + maxhp.peek())) / 2;
    }
    else
    {
        if (minhp.count() < maxhp.count())
        {
            return (double)maxhp.peek();
        }
        else
            return (double)minhp.peek();
    }
}
int main()
{

    int n = 12;
    int a[n] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    double median[n];
    for (int i = 0; i < n; i++)
    {
        int number = a[i];
        addToHeap(number);
        balanceHeaps();
        median[i] = findMedian();
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Median after reading " << i + 1 << " element is " << median[i] << endl;
    }

    return 0;
}