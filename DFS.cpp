/* DFS - Depth First Search - graph */
#include <bits/stdc++.h>
using namespace std;

void DFS(list<int> graph[], int node, bool visited[]) 
{
    visited[node] = true;
    cout << node << " ";

    for (int adjacent : graph[node]) {
        if (!visited[adjacent]) {
            DFS(graph, adjacent, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int V, E;
        cin >> V >> E;

        list<int> graph[V];
        bool visited[V];
        for(int i=0; i<V; i++)
        {
            visited[i]=false;
        }
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u); 
        }
        DFS(graph, 0, visited);
        cout << endl;
    }

    return 0;
}

