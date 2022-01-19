#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    int array[n] = {2, 3, 7, 9, 11, 2, 3, 11};
    int checker = array[0];
    int set_bit;
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
    {
        checker = checker ^ array[i];
    }
    cout << checker << endl;

    set_bit = checker & ~(checker - 1);

    for (int i = 0; i < n; i++)
    {
        if (array[i] & set_bit)
        {
            x = x ^ array[i];
        }
        else
        {
            y = y ^ array[i];
        }
    }

    cout << "Non Repeating Elements: " << x << "," << y;

    return 0;
}