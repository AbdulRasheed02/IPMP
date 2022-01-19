#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int n = 8;
    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8};
    int randIndex;
    int lastIndex = n - 1;
    for (int i = 0; i < n; i++)
    {
        int randIndex = rand() % (lastIndex + 1);
        int temp = a[lastIndex];
        a[lastIndex] = a[randIndex];
        a[randIndex] = temp;
        lastIndex--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }

    return 0;
}