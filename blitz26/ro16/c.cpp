//
// c.cpp
// Created by wasifshahzad on 03/15/26 at 15:18:31.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(all(a));
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    while(q--) {
        int x, y;
        cin >> x >> y;
        int l = n - x, r = n - x + y;
        cout << pref[r] - pref[l] << '\n';
    }
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