#include <iostream>
#include "tree.cpp"
#include <queue>
using namespace std;
bool firstNode = true;

void getLeftView(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 0)
    {
        if (firstNode)
        {
            cout << root->value << " ";
            firstNode = false;
        }
        return;
    }
    getLeftView(root->left, level - 1);
    getLeftView(root->right, level - 1);
}

void leftView(node *root, int height)
{
    for (int i = 0; i < height; i++)
    {
        getLeftView(root, i);
        firstNode = true;
    }
}
int main()
{
    node *root = new node(10);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->right->right = new node(15);
    root->right->left = new node(12);
    root->right->right->left = new node(14);
    tree t;
    leftView(root, t.getHeight(root));

    // node *empty = new node(INT_MIN);
    // queue<node *> q;
    // q.push(root);
    // q.push(empty);
    // bool firstOfLevel = true;
    // while (!q.empty())
    // {
    //     node *temp = q.front();
    //     q.pop();
    //     if (temp == empty)
    //     {
    //         if (firstOfLevel == false)
    //         {
    //             firstOfLevel = true;
    //         }
    //         if (q.size() == 0)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             q.push(empty);
    //         }
    //     }
    //     else
    //     {
    //         if (firstOfLevel)
    //         {
    //             cout << temp->value << " ";
    //             firstOfLevel = false;
    //         }
    //         if (temp->left != NULL)
    //         {
    //             q.push(temp->left);
    //         }
    //         if (temp->right != NULL)
    //         {
    //             q.push(temp->right);
    //         }
    //     }
    // }

    return 0;
}