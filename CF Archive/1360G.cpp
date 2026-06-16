//
// 1360G.cpp
// Created by wasifshahzad on 04/10/26 at 11:21:43.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
[1, 1, 0, 0, 0, 0]
[1, 1, 0, 0, 0, 0]
[1, 1, 0, 0, 0, 0]

[1, 1, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0]
*/

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n * a != m * b) {
        cout << "NO\n";
        return;
    }
    vector<int> freq(m, b);
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        vector<int> ord(m);
        iota(all(ord), 0);
        sort(ord.begin(), ord.end(), [&] (int i, int j) {
            return freq[i] > freq[j];
        });
        for(int j = 0; j < a; j++) {
            ans[i][ord[j]] = 1;
            freq[ord[j]]--;
        }
    }
    for(int i = 0; i < n; i++) {
        if(accumulate(all(ans[i]), 0ll) != a) {
            cout << "NO\n";
            return;
        }
    }
    for(int j = 0; j < m; j++) {
        int cur = 0;
        for(int i = 0; i < n; i++) cur += ans[i][j];
        if(cur != b) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}