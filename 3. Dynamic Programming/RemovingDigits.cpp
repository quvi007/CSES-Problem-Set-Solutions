#include <bits/stdc++.h>
using namespace std;

#define long long long

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, INF);
    
    for (int i = 0; i < 10; ++i) 
        dp[i] = 1;

    for (int i = 10; i <= n; ++i) {
        int x = i;
        set<int> digits;
        while (x) {
            if (x % 10) digits.insert(x % 10);
            x /= 10;
        }
        for (int digit : digits) 
            dp[i] = min(dp[i], dp[i - digit] + 1);
    }
    cout << dp[n] << "\n";
    return 0;
}