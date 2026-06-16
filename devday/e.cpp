//
// e.cpp
// Created by wasifshahzad on 04/30/26 at 13:27:07.
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
    vector<vector<pair<int, int>>> a(51);
    for(int i = 0; i < n; i++) {
        int l, r, v;
        cin >>l >> r >> v;
        a[l].push_back({r, v});
    }
    vector<int> dp(52, 0);
    for(int i = 50; i >= 0; i--) {
        dp[i] = dp[i + 1];
        for(auto [r, v]: a[i]) {
            dp[i] = max(dp[i], v + dp[r]);
        }
    }
    cout << dp[0] << '\n';
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