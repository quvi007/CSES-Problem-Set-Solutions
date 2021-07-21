#include <bits/stdc++.h>
using namespace std;

#define long long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long n;
    cin >> n;

    long sum = n * (n + 1) / 2;
    long s_sum = 0;
    for (int i = 1; i <= n - 1; ++i) {
        int x;
        cin >> x;
        s_sum += x;
    }
    cout << sum - s_sum << "\n";
    return 0;
}