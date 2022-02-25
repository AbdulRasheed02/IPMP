#include <iostream>
#include "graph.cpp"
using namespace std;
map<int, bool> visited;
void dfs(Graph g, int v)
{
    visited[v] = true;
    cout << v << " ";
    for (auto x : g.adjList[v])
    {
        if (!visited[x])
        {
            dfs(g, x);
        }
    }
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
    int v = 2;
    cout << "DFS: ";
    dfs(g, v);
    return 0;
}