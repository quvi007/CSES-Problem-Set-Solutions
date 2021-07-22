#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int prev_parents[N], new_parents[N];

int rep(int *parent, int u) {
    while (parent[u] != u)
        u = parent[u];
    return u;
}

void union_set(int *parents, int u, int v) {
    if (rep(parents, u) != rep(parents, v)) {
        parents[rep(parents, v)] = rep(parents, u);
    }
}

bool in_same_set(int *parents, int u, int v) {
    return rep(parents, u) == rep(parents, v);
}

int main() {
    int n, m;
    cin >> n >> m;
    map<char, vector<char>> next_states;
    map<char, vector<int>> outputs;

    for (int i = 0; i < n; ++i) {
        cout << (char)('A' + i) << "\t";
        vector<char> next_states_row(m);
        vector<int> outputs_row(m);
        for (int j = 0; j < m; ++j)
            cin >> next_states_row[j] >> outputs_row[j];
        next_states['A' + i] = next_states_row;
        outputs['A' + i] = outputs_row;
    }

    for (int i = 0; i < n; ++i)
        prev_parents[i] = i;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (outputs['A' + i] == outputs['A' + j])  
                union_set(prev_parents, i, j);
        }
    }
    
    while (true) {
        for (int i = 0; i < n; ++i) {
            new_parents[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!in_same_set(prev_parents, i, j)) continue;
                bool flag = true;
                for (int k = 0; k < m; ++k) {
                    if (!in_same_set(prev_parents, next_states['A' + i][k] - 'A', next_states['A' + j][k] - 'A')) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    union_set(new_parents, i, j);
            }
        }
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (prev_parents[i] != new_parents[i]) {
                flag = false;
                break;
            }
        }
        if (flag) break;
        for (int i = 0; i < n; ++i) {
            prev_parents[i] = new_parents[i];
        }
    }
    set<char> ans;
    for (int i = 0; i < n; ++i) {
        ans.insert('A' + rep(prev_parents, i));
    }
    for (char c : ans) {
        cout << "(";
        for (int i = 0; i < n; ++i) {
            if (prev_parents[i] == c - 'A')
                cout << (char)('A' + i);
        }
        cout << ")";
    }
    return 0;
}