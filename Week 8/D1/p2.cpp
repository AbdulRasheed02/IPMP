#include "tree.cpp"
#include <iostream>
using namespace std;
class child : public tree
{
public:
    void postorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        delete (root);
    }
};
int main()
{
    child t;
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    cout << t.getSize(root) << endl;
    t.postorder(root);
    root = NULL;

    return 0;
}