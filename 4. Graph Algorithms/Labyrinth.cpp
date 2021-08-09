#include <bits/stdc++.h>
using namespace std;

// Simple 2D BFS

typedef pair<int, int> pii;

const int INF = -1;

int fx[]{0, -1, 1, 0}, fy[]{-1, 0, 0, 1};

char dir(pii x, pii y) {
    if (x.first == y.first) {
        if (x.second == y.second - 1) return 'L';
        else return 'R';
    } else {
        if (x.first == y.first - 1) return 'U';
        else return 'D';
    }
}

void bfs(pii src, pii dest, vector<vector<int>> &distance, vector<vector<pii>> &prev, vector<vector<bool>> &visited, const vector<vector<char>> &grid) {
    distance[src.first][src.second] = 0;
    prev[src.first][src.second] = src;
    visited[src.first][src.second] = true;
    queue<pii> q;
    q.push(src);
    while(!q.empty()) {
        pii v = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pii u = {v.first + fx[i], v.second + fy[i]};
            if (visited[u.first][u.second] || grid[u.first][u.second] == '#') continue;
            q.push(u);
            visited[u.first][u.second] = true;
            distance[u.first][u.second] = distance[v.first][v.second] + 1;
            prev[u.first][u.second] = v;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '#'));
    pii src, dest;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                src = {i, j};
            else if (grid[i][j] == 'B')
                dest = {i, j};
        }
    }

    vector<vector<int>> distance(n + 2, vector<int>(m + 2, INF));
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));
    vector<vector<pii>> prev(n + 2, vector<pii>(m + 2));

    bfs(src, dest, distance, prev, visited, grid);
    string ans;
    if (distance[dest.first][dest.second] != -1) {
        cout << "YES\n";
        pii v = dest;
        while(prev[v.first][v.second] != v) {
            ans += dir(v, prev[v.first][v.second]);
            v = prev[v.first][v.second];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.length() << "\n" << ans << "\n";
    } else cout << "NO\n";
    return 0;
}