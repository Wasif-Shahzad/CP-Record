//
// 1438C.cpp
// Created by wasifshahzad on 06/21/26 at 20:08:34.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // there are some cells increasing which will force a series of actions
    // this can be avoided tho by increasing the cell which doesn't do it
    // we can map it as a graph idk if its too much
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            if((i + j) & 1) cout << x + (x % 2 == 0) << " ";
            else cout << x + (x & 1) << " ";
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