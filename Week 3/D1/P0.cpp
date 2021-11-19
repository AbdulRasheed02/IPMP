#include <iostream>
using namespace std;
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

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = array[i];
        while (array[j] > key && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    cout << "Sorted Array:";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
}