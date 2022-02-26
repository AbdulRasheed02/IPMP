#include <iostream>
#include <map>
using namespace std;
const int n = 5;
bool safe(int adjMat[n][n], int x, int y)
{
    if (x >= 0 && x < n && y <= 0 && y < n && adjMat[x][y] == 1)
    {
        return true;
    }
    return false;
}
void dfs(int adjMat[n][n], int i, int j)
{
    adjMat[i][j] = 2;
    if (safe(adjMat, i - 1, j - 1))
    {
        dfs(adjMat, i - 1, j - 1);
    }
    if (safe(adjMat, i - 1, j))
    {
        dfs(adjMat, i - 1, j);
    }
    if (safe(adjMat, i - 1, j + 1))
    {
        dfs(adjMat, i - 1, j + 1);
    }
    if (safe(adjMat, i, j - 1))
    {
        dfs(adjMat, i, j - 1);
    }
    if (safe(adjMat, i, j + 1))
    {
        dfs(adjMat, i, j + 1);
    }
    if (safe(adjMat, i + 1, j - 1))
    {
        dfs(adjMat, i + 1, j - 1);
    }
    if (safe(adjMat, i + 1, j))
    {
        dfs(adjMat, i + 1, j);
    }
    if (safe(adjMat, i + 1, j + 1))
    {
        dfs(adjMat, i + 1, j + 1);
    }
}
int islandCount(int adjMat[n][n])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMat[i][j] == 1)
            {
                count++;
                dfs(adjMat, i, j);
            }
        }
    }
    return count;
}
int main()
{
    int adjMat[n][n] = {{1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1}};
    cout << islandCount(adjMat);
    return 0;
}