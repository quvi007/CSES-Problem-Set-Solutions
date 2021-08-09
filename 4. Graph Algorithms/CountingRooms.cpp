#include <bits/stdc++.h>
using namespace std;

// Number of Connected Components

int fx[] = {-1, 0, 0, 1}, fy[] = {0, -1, 1, 0};

void dfs(int i, int j, vector<vector<bool>> &visited, const vector<vector<char>> &grid) {
    if (visited[i][j]) return; 
    visited[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int x = j + fx[k];
        int y = i + fy[k];
        if (grid[y][x] == '#') continue;
        dfs(y, x, visited, grid);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '#'));
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(visited[i][j] || grid[i][j] == '#') continue;
            ans++;
            dfs(i, j, visited, grid);
        }
    }
    cout << ans << "\n";
    return 0;
}