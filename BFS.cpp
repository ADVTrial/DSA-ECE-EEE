/* BFS - Breadth First Search - graph */
#include <bits/stdc++.h>
using namespace std;

void BFS(list<int> graph[], int start, bool visited[]) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int adjacent : graph[current]) {
            if (!visited[adjacent]) {
                q.push(adjacent);
                visited[adjacent] = true;
            }
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
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        bool visited[V];
        for(int i=0; i<V; i++)
        {
            visited[i]=false;
        }
        BFS(graph, 0, visited);
        cout << endl;
    }
    return 0;
}
