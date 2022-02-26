#include <iostream>
#include "graph.cpp"
#include <stack>
using namespace std;

void topologicalSort(Graph g, stack<int> &s, bool *visited, int v)
{
    visited[v] = true;
    for (auto x : g.adjList[v])
    {
        if (!visited[x])
        {
            topologicalSort(g, s, visited, x);
        }
    }
    s.push(v);
}
void topological(Graph g, int V)
{
    stack<int> s;
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSort(g, s, visited, i);
        }
    }
    int top;
    while (!s.empty())
    {
        top = s.top();
        s.pop();
        cout << top << " ";
    }
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.print();
    cout << "Topological Sort: ";
    topological(g, 6);
    return 0;
}