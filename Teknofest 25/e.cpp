//
// e.cpp
// Created by wasifshahzad on 01/03/26 at 12:52:54.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<vector<int>> loc(1e5 + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        loc[a[i].second].push_back(i);
    }
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        int j = upper_bound(a.begin(), a.end(), pair<int, int>{x, 1e6}) - a.begin();
        int k = lower_bound(loc[y].begin(), loc[y].end(), j) - loc[y].begin();
        int ans = j - k;
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}