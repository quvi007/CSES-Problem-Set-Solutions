#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];

void buildSet(int n) {
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
}

int findRep(int u) {
    int v = u;
    while (parent[v] != v) {
        v = parent[v];
    }
    return parent[u] = v;
}

void unionSet(int u, int v) {
    int a = findRep(u), b = findRep(v);
    if (a == b) return;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    buildSet(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        unionSet(u, v);
    }
    set<int> nodes;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        nodes.insert(findRep(i));
    }
    cout << nodes.size() - 1 << "\n";
    for (int x : nodes) ans.push_back(x);
    for (int i = 0; i < (int)ans.size() - 1; ++i) cout << ans[i] << " " << ans[i + 1] << "\n";
    return 0;
}