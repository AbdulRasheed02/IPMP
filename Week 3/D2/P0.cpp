#include <iostream>
using namespace std;
int partition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (array[i] <= pivot);
        do
        {
            j--;
        } while (array[j] > pivot);
        if (i < j)
        {
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    int temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}
void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int j = partition(array, low, high);
        quickSort(array, low, j);
        quickSort(array, j + 1, high);
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

    quickSort(array, 0, n);

    cout << "Sorted Array:";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
}