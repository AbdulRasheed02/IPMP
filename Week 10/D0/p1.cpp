#include <iostream>
#include "graph.cpp"
#include "queue"
using namespace std;
map<int, bool> visited;
void bfs(Graph g, int v)
{
    queue<int> q;
    visited[v] = true;
    q.push(v);
    int current;
    while (!q.empty())
    {
        current = q.front();
        q.pop();
        cout << current << " ";
        for (auto x : g.adjList[current])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
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
    cout << "BFS: ";
    bfs(g, v);
    return 0;
}