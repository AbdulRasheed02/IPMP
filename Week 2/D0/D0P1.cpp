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

    bool swapped = true;

    for (int i = 0; i < n - 1; i++)
    {
        if (swapped)
        {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;
                    swapped = true;
                }
            }
        }
    }

    cout << "Sorted Array:";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
}