#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*' || i == 0 && j == 0) continue;
            if (i > 0 && grid[i - 1][j] == '.') dp[i][j] = dp[i - 1][j];
            if (j > 0 && grid[i][j - 1] == '.') dp[i][j] += dp[i][j - 1];
            dp[i][j] %= M;
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}