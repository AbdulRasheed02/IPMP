#include <iostream>
using namespace std;
void merge(int array[], int temp[], int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= high)
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = array[i];
            i++;
            k++;
        }
    }
    for (int i = low; i <= high; i++)
        array[i] = temp[i];
}
void mergeSort(int array[], int temp[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(array, temp, low, mid);
        mergeSort(array, temp, mid + 1, high);
        merge(array, temp, low, mid, high);
    }
}
int main()
{
    int n;
    cout << "No. of Elements in array:";
    cin >> n;
    int array[n], temp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    mergeSort(array, temp, 0, n - 1);

    cout << "Sorted Array:";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
}