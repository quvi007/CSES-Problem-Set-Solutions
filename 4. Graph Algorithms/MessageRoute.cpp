#include <bits/stdc++.h>
using namespace std;

// Plain BFS

const int INF = -1, N = 1e5 + 5;
vector<int> adj[N];
int p[N], dist[N];
bool visited[N];

void bfs(int src, int dest) {
    memset(dist, INF, sizeof(dist));
    queue<int> q;
    q.push(src);
    dist[src] = 1;
    visited[src] = true;
    p[src] = src;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                p[u] = v;
                q.push(u);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, n);
    if (dist[n] == INF) cout << "IMPOSSIBLE\n";
    else {
        int v = n;
        cout << dist[n] << "\n";
        vector<int> nodes;
        while (true) {
            nodes.push_back(v);
            if (v == p[v]) break;
            v = p[v];
        }
        reverse(nodes.begin(), nodes.end());
        for (int i = 0; i < nodes.size(); ++i) cout << nodes[i] << ' ';
        cout << "\n";
    }
    return 0;
}