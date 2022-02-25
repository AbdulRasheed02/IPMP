#include <iostream>
#include "bst.cpp"
using namespace std;
int largestBST(node *root, bool *isBST, int *maxSize, int *min, int *max)
{
    if (root == NULL)
    {
        *isBST = true;
        return 0;
    }

    int mininimum = INT_MAX;

    bool left = false, right = false;
    int leftSum, rightSum;

    *max = INT_MIN;
    leftSum = largestBST(root->left, isBST, maxSize, min, max);
    if (*isBST && root->value > *max)
        left = true;

    mininimum = *min;
    *min = INT_MAX;
    rightSum = largestBST(root->right, isBST, maxSize, min, max);
    if (*isBST && root->value < *min)
        right = true;

    if (mininimum < *min)
        *min = mininimum;
    if (root->value < *min)
        *min = root->value;
    if (root->value > *max)
        *max = root->value;

    if (left && right)
    {
        if (leftSum + rightSum + 1 > *maxSize)
        {
            *maxSize = leftSum + rightSum + 1;
        }
        return leftSum + rightSum + 1;
    }
    else
    {
        *isBST = false;
        return 0;
    }
}
int main()
{
    node *root = new node(50);
    root->left = new node(10);
    root->right = new node(60);
    root->left->left = new node(5);
    root->left->right = new node(20);
    root->right->left = new node(55);
    root->right->left->left = new node(45);
    root->right->right = new node(70);
    root->right->right->left = new node(65);
    root->right->right->right = new node(80);
    bool isBST = false;
    int min = INT_MAX;
    int max = INT_MIN;
    int maxSize = 0;
    int largest = largestBST(root, &isBST, &maxSize, &min, &max);
    cout << maxSize;
    return 0;
}