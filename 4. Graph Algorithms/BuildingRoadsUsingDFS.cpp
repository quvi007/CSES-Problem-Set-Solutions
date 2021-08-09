#include <bits/stdc++.h>
using namespace std;

// Number of connected Components
// I guess it can be done using DSU too

void dfs(int v, vector<bool> &visited, vector<int> *adj) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (visited[u]) continue;
        dfs(u, visited, adj);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<bool> visited(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    int ans = 0;
    vector<int> nodes;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        ans++;
        nodes.push_back(i);
        dfs(i, visited, adj);
    }
    cout << ans - 1 << "\n";
    for (int i = 0; i < nodes.size() - 1; ++i)
        cout << nodes[i] << " " << nodes[i + 1] << "\n";
    return 0;
}