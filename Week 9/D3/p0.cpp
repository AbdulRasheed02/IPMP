#include <iostream>
#include "bst.cpp"
using namespace std;
node *arrayToBST(int array[], int left, int right)
{
    if (left > right)
    {
        return NULL;
    }
    int mid = (left + right) / 2;
    node *root = new node(array[mid]);

    root->left = arrayToBST(array, left, mid - 1);
    root->right = arrayToBST(array, mid + 1, right);

    return root;
}
int main()
{
    int n = 4;
    int array[n] = {1, 2, 3, 4};
    int left = 0;
    int right = n - 1;
    node *root = arrayToBST(array, left, right);
    tree t;
    t.levelOrder(root);
    return 0;
}