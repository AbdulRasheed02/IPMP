#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int m = 4;
    int a1[n] = {1, 3, 4, 5, 7};
    int a2[m] = {2, 3, 5, 6};
    int i = 0, j = 0, k1 = 0, k2 = 0;
    int uni[100], inter[100];
    while (i < n && j < m)
    {
        if (a1[i] == a2[j])
        {
            uni[k1] = a1[i];
            inter[k2] = a1[i];
            i++;
            j++;
            k2++;
        }
        else
        {
            if (a1[i] < a2[j])
            {
                uni[k1] = a1[i];
                i++;
            }
            else
            {
                uni[k1] = a2[j];
                j++;
            }
        }
        k1++;
    }

    while (j < m)
    {
        uni[k1] = a2[j];
        j++;
        k1++;
    }

    while (i < n)
    {
        uni[k1] = a1[i];
        i++;
        k1++;
    }

    cout << "Union of Array: ";
    for (int a = 0; a < k1; a++)
    {
        cout << uni[a] << ",";
    }
    cout << endl;

    cout << "Intersection of Array: ";
    for (int a = 0; a < k2; a++)
    {
        cout << inter[a] << ",";
    }
    cout << endl;

    return 0;
}