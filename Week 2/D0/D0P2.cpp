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

    for (int i = 0; i < n - 1; i++)
    {
        int indexMin = array[i];
        for (int j = i + 1; j < n; j++)
        {

            if (array[j] < array[indexMin])
            {
                indexMin = j;
            }
        }
        int temp = array[i];
        array[i] = array[indexMin];
        array[indexMin] = temp;
    }

    cout << "Sorted Array:";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ",";
    }
}