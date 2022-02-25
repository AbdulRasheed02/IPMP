#include <iostream>
#include "bst.cpp"
using namespace std;
struct dta
{
    int size;
    int min;
    int max;
    int sizeBST;
    bool isBST;
};
dta largestBST(node *root)
{
    if (root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->value, root->value, 1, true};
    }
    dta left = largestBST(root->left);
    dta right = largestBST(root->right);
    dta result;
    result.size = left.size + right.size + 1;
    if (left.isBST && right.isBST && root->value > left.max && root->value < right.min)
    {
        result.min = min(left.min, root->value);
        result.max = max(right.max, root->value);
        result.isBST = true;
        result.sizeBST = result.size;
        return result;
    }
    result.isBST = false;
    result.sizeBST = max(left.sizeBST, right.sizeBST);
    return result;
}
int main()
{
    node *root = new node(60);
    root->left = new node(65);
    root->right = new node(70);
    root->left->left = new node(50);
    int largest = largestBST(root).sizeBST;
    cout << largest;
    return 0;
}