#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int n = 7;
    int a[n] = {1, 4, -2, -2, 5, -4, 3};
    int sum;
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0 || umap[sum] > 0)
        {
            cout << "Sub Array Exists";
            return true;
        }
        umap[sum]++;
    }
    cout << "Sub Array Does not Exist";
    return 0;
}