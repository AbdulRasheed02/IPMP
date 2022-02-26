#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void addEdge(vector<vector<int>> &edges, int u, int v, int w)
{
    edges.push_back({u, v, w});
}
bool comparator(vector<int> edgeA, vector<int> edgeB)
{
    return edgeA[2] < edgeB[2];
}
void make_set(int *parent, int V)
{
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
}
int find(int *parent, int x)
{
    if (x != parent[x])
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}
void union_set(int *parent, int *rank, int u, int v)
{
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU == rootV)
    {
        return;
    }
    if (rank[rootU] > rank[rootV])
    {
        parent[rootV] = rootU;
    }
    else
    {
        parent[rootU] = rootV;
        if (rank[rootU] == rank[rootV])
        {
            rank[rootV]++;
        }
    }
}
vector<vector<int>> kruskal(vector<vector<int>> &edges, int V)
{
    int parent[V];
    int rank[V];
    vector<vector<int>> result;
    make_set(parent, V);
    sort(edges.begin(), edges.end(), comparator);
    for (int i = 0; i < edges.size(); i++)
    {

        if (find(parent, edges[i][0]) != find(parent, edges[i][1]))
        {

            result.push_back(edges[i]);
            union_set(parent, rank, edges[i][0], edges[i][1]);
        }
    }

    return result;
}
int main()
{
    int V = 4;
    vector<vector<int>> edges;
    addEdge(edges, 0, 1, 10);
    addEdge(edges, 1, 3, 15);
    addEdge(edges, 2, 3, 4);
    addEdge(edges, 2, 0, 6);
    addEdge(edges, 0, 3, 5);
    vector<vector<int>> result = kruskal(edges, V);
    int weight = 0;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << "-" << result[i][1] << "  -  " << result[i][2] << endl;
        weight += result[i][2];
    }
    cout << "Weight: " << weight;
    return 0;
}