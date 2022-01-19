#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 8;
    int a[n] = {1, 2, 3, 4, 6, 5, 7, 8};
    int x = 16;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    int LL = 0;
    int LR = 1;
    int RL = n - 2;
    int RR = n - 1;
    //cout << LL << "," << LR << "," << RL << "," << RR << endl;
    while (LR < RL)
    {
        if ((a[LL] + a[LR] + a[RL] + a[RR]) > x)
        {
            //cout << (a[LL] + a[LR] + a[RR] + a[RR]) << endl;
            if (a[RL] - a[RL - 1] < ((a[RR] + a[RL]) - (a[RL] + a[RL - 1])))
            {
                RL--;
            }
            else
            {
                RL--;
                RR--;
            }
        }
        else if ((a[LL] + a[LR] + a[RL] + a[RR]) < x)
        {

            if (a[LR + 1] - a[LR] < ((a[LR + 1] + a[LR]) - (a[LL] + a[LR])))
            {
                LR++;
            }
            else
            {
                LL++;
                LR++;
            }
        }
        else
        {
            cout << "The four elements are:" << a[LL] << "," << a[LR] << "," << a[RL] << "," << a[RR];
            return 0;
        }
        //cout << LL << "," << LR << "," << RL << "," << RR << endl;
    }
    cout << "No such four elements exists";
    return 0;
}