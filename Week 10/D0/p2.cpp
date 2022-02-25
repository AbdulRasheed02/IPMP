#include <iostream>
#include "graph.cpp"
#include <map>
using namespace std;
bool containsCycle(Graph g, int v, map<int, bool> visited, map<int, bool> recursionStack)
{
    if (!visited[v])
    {
        visited[v] = true;
        recursionStack[v] = true;
        for (auto x : g.adjList[v])
        {
            if (!visited[x] && containsCycle(g, x, visited, recursionStack))
            {
                return true;
            }
            else if (recursionStack[v])
            {
                return true;
            }
        }
    }
    recursionStack[v] = false;
    return false;
}
bool cycle(Graph g, int n)
{
    map<int, bool> visited;
    map<int, bool> recursionStack;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && containsCycle(g, i, visited, recursionStack))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.print();
    cout << boolalpha << cycle(g, 4);
    return 0;
}