#include <iostream>
#include <stack>
#include "graph.cpp"
#include <vector>
using namespace std;
void dfs(Graph g, stack<int> &s, bool *visited, int v)
{
    visited[v] = true;
    for (auto x : g.adjList[v])
    {
        if (!visited[x])
        {
            dfs(g, s, visited, x);
        }
    }
    s.push(v);
}
void dfsReverse(Graph g, bool *visited, int v, vector<int> &component)
{
    visited[v] = true;
    component.push_back(v);
    for (auto x : g.adjList[v])
    {
        if (!visited[x])
        {
            dfsReverse(g, visited, x, component);
        }
    }
}
Graph reverseGraph(Graph g)
{
    Graph gReverse(g.V);
    for (int i = 0; i < g.V; i++)
    {
        for (auto it = g.adjList[i].begin(); it != g.adjList[i].end(); it++)
        {
            gReverse.addEdge(*it, i);
        }
    }
    return gReverse;
}
vector<vector<int>> stronglyConnectedComponent(Graph g)
{

    stack<int> s;
    bool visited[g.V];
    for (int i = 0; i < g.V; i++)
    {
        if (!visited[i])
        {
            dfs(g, s, visited, i);
        }
    }
    Graph gReverse = reverseGraph(g);
    for (int i = 0; i < g.V; i++)
    {
        visited[i] = false;
    }
    vector<vector<int>> result;
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        if (!visited[x])
        {
            vector<int> component;
            dfsReverse(gReverse, visited, x, component);
            result.push_back(component);
        }
    }
    return result;
}
int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    vector<vector<int>> result = stronglyConnectedComponent(g);
    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}