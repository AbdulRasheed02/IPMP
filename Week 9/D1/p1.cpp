#include <iostream>
#include <stack>
#include "bst.cpp"
using namespace std;
void pushLeft(node *root, stack<node *> &s1)
{
    while (root)
    {
        s1.push(root);
        root = root->left;
    }
}
void pushRight(node *root, stack<node *> &s2)
{
    while (root)
    {
        s2.push(root);
        root = root->right;
    }
}
bool targetExists(node *root, int sum)
{
    stack<node *> s1, s2;
    pushLeft(root, s1);
    pushRight(root, s2);
    node *low = s1.top();
    node *high = s2.top();
    while (low != NULL && high != NULL && low->value < high->value)
    {
        int sm = low->value + high->value;
        if (sm < sum)
        {
            pushLeft(low->right, s1);
            low = s1.top();
            s1.pop();
        }
        else if (sm > sum)
        {
            pushRight(high->left, s2);
            high = s2.top();
            s2.pop();
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    bst b;
    node *root = NULL;
    root = b.insert(root, 15);
    b.insert(root, 7);
    b.insert(root, 20);
    b.insert(root, 2);
    b.insert(root, 12);
    b.insert(root, 17);
    b.insert(root, 10);
    b.insert(root, 14);
    b.insert(root, 19);
    // b.levelOrder(root);
    int sum = 36;
    cout << boolalpha << targetExists(root, sum);

    return 0;
}