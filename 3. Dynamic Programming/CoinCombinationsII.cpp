#include <bits/stdc++.h>
using namespace std;

#define long long long

const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int &coin : coins)
        cin >> coin;
    
    vector<long> dp(x + 1, 0);
    dp[0] = 1;
    
    for (int coin : coins) {
        for (int i = 1; i <= x; ++i) {
            if (coin <= i) (dp[i] += dp[i - coin]) %= M;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}