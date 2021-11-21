#include <iostream>
using namespace std;
int main()
{
    cout << "Enter Word:";
    string input;
    cin >> input;
    int checker = 0;
    for (int i = 0; i < input.length(); i++)
    {
        int bitIndex = input[i] - 'a';
        checker = checker ^ (1 << bitIndex);
    }

    if (input.length() % 2 == 0 && checker == 0)
    {
        cout << "Given Word can be arranged into a palindrome";
        return 0;
    }
    else if (input.length() % 2 == 1)
    {

        if ((checker & (checker - 1)) == 0)
        {
            cout << "Given Word can be arranged into a palindrome";
            return 0;
        }
    }
    cout << "Given Word cannot be arranged into a palindrome";
    return 0;
}