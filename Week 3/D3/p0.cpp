#include <iostream>
#include <algorithm>
using namespace std;
struct pr
{
    int start;
    int finish;
};
bool comparator(pr p1, pr p2)
{
    return (p1.finish < p2.finish);
}
int main()
{
    int n = 6;
    struct pr a[n] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    sort(a, a + n, comparator);

    cout << "\nSorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << "{" << a[i].start << "," << a[i].finish << "}"
             << ",";
    }

    struct pr result[n];
    int index = 0;
    result[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i].start >= result[index].finish)
        {
            index++;
            result[index] = a[i];
        }
    }

    cout << "\nResult: ";
    for (int i = 0; i < index + 1; i++)
    {
        cout << "{" << result[i].start << "," << result[i].finish << "}"
             << ",";
    }

    cout << endl;
    return 0;
}