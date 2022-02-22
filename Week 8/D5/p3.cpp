#include <iostream>
using namespace std;
class node
{
public:
    // No.of Alphabets
    node *next[26];
    bool endofWord;
    node()
    {
        endofWord = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};
void insert(node *root, string word)
{
    node *iterator = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (iterator->next[word[i] - 'a'] == NULL)
        {
            iterator->next[word[i] - 'a'] = new node();
        }
        iterator = iterator->next[word[i] - 'a'];
    }
    iterator->endofWord = true;
}
bool search(node *root, string word)
{
    node *iterator = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (iterator->next[word[i] - 'a'] == NULL)
        {
            return false;
        }
        iterator = iterator->next[word[i] - 'a'];
    }
    return iterator->endofWord;
}
int main()
{
    node *root = new node();
    insert(root, "the");
    insert(root, "there");
    insert(root, "hi");
    insert(root, "bye");
    insert(root, "abdulrasheed");

    cout << boolalpha << search(root, "abdulrasheed") << endl;
    cout << boolalpha << search(root, "hello") << endl;
    cout << boolalpha << search(root, "bye") << endl;
    cout << boolalpha << search(root, "th");

    return 0;
}