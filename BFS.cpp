#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>>& adjList, int e1, int e2)
{
    adjList[e1].push_back(e2);
    adjList[e2].push_back(e1);
}

void BFS(vector<vector<int>>& adjList, vector<bool>& visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        cout << t << " ";
        for (auto it:adjList[t])
        {
            if (!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n);
    for (int i=0; i<e; i++)
    {
        int x,y;
        cin >> x >> y;
        addEdge(adjList, x, y);
    }
    vector<bool> v(n,0);
    BFS(adjList, v, 0);
    return 0;
}
