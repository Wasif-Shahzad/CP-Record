//
// c.cpp
// Created by wasifshahzad on 03/13/26 at 23:46:10.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = -1e10;
    for(int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        ans = max(ans, f - max(0ll, t - k));
    }
    cout << ans << '\n';
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