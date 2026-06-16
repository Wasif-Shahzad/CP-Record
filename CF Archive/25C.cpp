//
// 25C.cpp
// Created by wasifshahzad on 04/12/26 at 21:22:22.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    int k;
    cin >> k;
    while(k--) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        d[a][b] = min(d[a][b], w);
        d[b][a] = d[a][b];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][a] + d[b][j] + d[a][b]);
                d[i][j] = min(d[i][j], d[i][b] + d[a][j] + d[a][b]);
            }
        }
        int sm = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sm += d[i][j];
            }
        }
        cout << sm / 2 << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}