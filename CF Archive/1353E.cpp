//
// 1353E.cpp
// Created by wasifshahzad on 04/18/26 at 21:26:24.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
for a subarray [l, r]
pref[r] - pref[l - 1] + tot - pref1[r] + pref1[l - 1]
pref1[l - 1] - pref[l - 1] + pref[r] - pref1[r] + tot
*/

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int o = count(all(s), '1');
    int ans = n;
    for(int i = 0; i < k; i++) {
        vector<int> a;
        for(int j = i; j < n; j += k) {
            a.push_back(s[j] - '0');
        }
        int m = a.size();
        int tot = accumulate(all(a), 0ll);
        int p1 = 0, p0 = 0;
        int mn = 1e9;
        int here = 1e9;
        for(int i = 0; i < m; i++) {
            mn = min(mn, p1 - p0);
            p1 += a[i];
            p0 += !a[i];
            here = min(here, p0 - p1 + tot + mn);
        }
        here = min(here, tot);
        ans = min(ans, here + o - tot);
    }
    cout << ans << '\n';
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