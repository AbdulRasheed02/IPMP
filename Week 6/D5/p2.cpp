#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
void swapCharacter(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverseString(char *s, int left, int right)
{
    while (left < right)
    {
        swapCharacter(&s[left], &s[right]);
        left++;
        right--;
    }
}
void cycleLeader(char *s, int shift, int length)
{
    char c;
    int x;
    for (int i = 1; i < length; i = 3 * i)
    {
        x = i;
        c = s[x + shift];
        do
        {
            if (x % 2 == 1)
            {
                x = length / 2 + x / 2;
            }
            else
            {
                x = x / 2;
            }
            swapCharacter(&s[x + shift], &c);
        } while (x != i);
    }
}
void transform(char *s)
{
    int k;
    int lengthFirst;
    int lengthRemaining = strlen(s);
    int shift = 0;
    while (lengthRemaining)
    {
        k = 0;
        while (pow(3, k) + 1 <= lengthRemaining)
        {
            k++;
        }
        lengthFirst = pow(3, k - 1) + 1;
        lengthRemaining = lengthRemaining - lengthFirst;

        cycleLeader(s, shift, lengthFirst);
        reverseString(s, shift / 2, shift - 1);
        reverseString(s, shift, shift + (lengthFirst / 2) - 1);
        reverseString(s, shift / 2, shift + (lengthFirst / 2) - 1);
        shift += lengthFirst;
    }
}
int main()
{
    char s[] = "a1b2c3d4e5f6g7";
    transform(s);
    cout << s;
    return 0;
}