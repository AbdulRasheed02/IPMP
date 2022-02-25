#ifndef graph_h
#define graph_h
#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{

public:
    int V;
    map<int, list<int>> adjList;
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "  ";
            for (auto j : adjList[i])
            {
                cout << "->" << j;
            }
            cout << endl;
        }
    }
};

#endif