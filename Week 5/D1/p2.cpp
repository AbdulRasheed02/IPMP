#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int array[n] = {8, 4, 2, 1};
    int count;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}