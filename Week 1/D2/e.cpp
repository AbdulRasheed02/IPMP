#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    for (int j = 0; j < 4; j++)
    {
        getline(cin, s);
        while (s.length() == 0)
        {
            getline(cin, s);
        }
        cout << s << " :line" << j << endl;
    }
    return 0;
}