#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N], color(N, -1);
bool visited[N], impossible = false;

void dfs(int v, int c) {
    visited[v] = true;
    color[v] = c;
    for (int u : adj[v]) {
        if (visited[u]) {
            if (color[u] == c) {
                impossible = true;
                return;
            }
        } else {
            dfs(u, 1 ^ c);
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

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    if (impossible) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 1; i <= n; ++i)
            cout << color[i] + 1 << " ";
        cout << "\n";
    }
    return 0;
}