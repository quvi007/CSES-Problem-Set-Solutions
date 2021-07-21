#include <bits/stdc++.h>
using namespace std;

#define long long long

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    long sum = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            sum += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << sum << "\n";
    return 0;
}