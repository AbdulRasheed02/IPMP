#include <iostream>
#include "graph.cpp"
#include <map>
using namespace std;

map<int, bool> visited;
void dfs(Graph g, int v)
{
    visited[v] = true;
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
    int u = 1;
    int v = 3;
    dfs(g, u);
    cout << boolalpha << visited[v];
    return 0;
}