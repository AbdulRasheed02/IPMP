#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
int smallerChar(string s, int index)
{
    int smallerchar = 0;
    for (int i = index + 1; i < s.length(); i++)
    {
        // cout << i << " " << index << endl;
        if (s[i] < s[index])
        {
            // cout << s[i] << " " << s[index] << endl;
            smallerchar++;
        }
    }
    return smallerchar * factorial(s.length() - index - 1);
}
int findPermutation(string s)
{
    int rank = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int rankAdd = smallerChar(s, i);
        rank += rankAdd;
    }
    rank += 1;
    return rank;
}
int main()
{
    string s = "string";
    int rank = findPermutation(s);
    cout << "Rank: " << rank;
    return 0;
}