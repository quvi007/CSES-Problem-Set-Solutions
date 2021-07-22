#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    
    vector<double> dp(b + 1, 1);
    
    for (int i = 1; i <= n; ++i) {
        vector<double> new_dp(b + 1);
        for (int x = 1; x <= b; ++x) {
            int l = x - 6;
            if (l < 0) l = 0;
            int r = x - 1;
            new_dp[x] = dp[r];
            if (l > 0) new_dp[x] -= dp[l - 1];
            new_dp[x] /= 6;
        }   
        for (int j = 1; j <= b; ++j)
            new_dp[j] += new_dp[j - 1];
        dp = new_dp;
    }
    double ans = dp[b] - dp[a - 1];
    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}