#include <iostream>
using namespace std;
int findRange(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
void countingSort(int array[], int n, int range)
{
    int count[range + 1];
    int temp[n];
    for (int i = 0; i <= range; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        ++count[array[i]];
    }
    for (int i = 1; i <= range; i++)
    {
        count[i] = count[i - 1] + count[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        temp[--count[array[i]]] = array[i];
    }
    for (int i = 0; i < n; i++)
    {
        array[i] = temp[i];
    }
}
int main()
{
    int n;
    cout << "No. of Elements in array:";
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int range = findRange(array, n);
    countingSort(array, n, range);

    cout << "Sorted Array:";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
}