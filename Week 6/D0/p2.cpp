#include <iostream>
using namespace std;
void search(char *text, char *pat)
{
    int n = 0;
    int m = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        n++;
    }
    for (int i = 0; pat[i] != '\0'; i++)
    {
        m++;
    }
    //cout << "n=" << n << ",m=" << m;
    cout << endl;
    for (int i = 0; i <= n - m; i++)
    {
        if (text[i] == pat[0])
        {
            int j = 1;
            while (j < m)
            {
                if (text[i + j] == pat[j])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            if (j == m)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }
    }
}
int main()
{
    char text[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    search(text, pat);
    return 0;
}