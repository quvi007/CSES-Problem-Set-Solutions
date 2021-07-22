#include <bits/stdc++.h>
using namespace std;

#define long long long

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int &x : c)
        cin >> x;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; ++i) {
        for (int coin : c) {
            if (coin > i) continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    if (dp[x] != INF) cout << dp[x] << "\n";
    else cout << -1 << "\n";
    return 0;
}