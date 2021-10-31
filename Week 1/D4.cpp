#include <iostream>
#include <unordered_map>
using namespace std;
class example
{
public:
    string hello;
    int x = 20;
    void printString()
    {
        cout << hello << endl;
    }
    void printX();
    example()
    {
        cout << "Constructor"
             << " x=" << x << endl;
    }
    example(const example &old)
    {
        x = old.x;
    }
    example(int y)
    {
        x = y;
        cout << "Parametrised Constructor"
             << " x=" << x << endl;
    }
    ~example()
    {
        x = 0;
        cout << "Destructor"
             << " x=" << x << endl;
    }
};
void example::printX()
{
    cout << x << endl;
}
int main()
{
    cout << "Enter String:" << endl;
    string s;
    cin >> s;
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] > 0)
        {
            cout << "Not Unique";
            return 0;
        }
        else
        {
            m[s[i]]++;
        }
    }
    cout << "Unique";

    example object;
    example object2(25);
    example object3 = object2;
    cout << "Original: " << object2.x << endl;
    cout << "Copied: " << object3.x << endl;

    return 0;
}