#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int mx = 0;
    int c = 1;
    for (int i = 0; i < s.length(); ++i) {
        if (i != 0 && s[i] == s[i - 1]) {
            c++;
            mx = max(mx, c);
        }
        else {
            mx = max(mx, c);
            c = 1;
        }
    }
    cout << mx << "\n";
    return 0;
}