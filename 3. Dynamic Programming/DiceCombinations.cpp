#include <bits/stdc++.h>
using namespace std;

#define long long long

const int M = 1e9 + 7, N = 1e6 + 5;

long dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6 && j <= i; ++j) 
            (dp[i] += dp[i - j]) %= M;
    }

    cout << dp[n] << "\n";

    return 0;
}