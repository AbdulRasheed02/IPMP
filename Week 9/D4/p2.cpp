#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
void print(vector<int> adjList[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "  ";
        for (auto j : adjList[i])
        {
            cout << "->" << j;
        }
        cout << endl;
    }
}
int main()
{
    int v = 5;
    vector<int> adjList[v];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    print(adjList, v);

    return 0;
}