//
// 1155D.cpp
// Created by wasifshahzad on 04/20/26 at 20:18:03.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
pref[l] + x * sum[l...r] + suff[r]
pref[l] + x * p[r] - x * p[l - 1] + suff[r]
pref[l] - x * p[l - 1] + x * p[r] + suff[r]
*/

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pref(n, 0), psum(n, 0);
    int cur = 0, mn = 0;
    for(int i = 0; i < n; i++) {
        pref[i] = cur - mn;
        cur += a[i];
        psum[i] = cur;
        mn = min(mn, cur);
    }
    int ans = cur - mn;
    ans = max(ans, *max_element(all(pref)));
    vector<int> suff(n, 0), bst(n, 0);
    cur = mn = 0;
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = cur - mn;
        bst[i] = suff[i] + x * psum[i];
        if(i + 1 < n) bst[i] = max(bst[i], bst[i + 1]);
        cur += a[i];
        mn = min(mn, cur);
    }
    for(int i = 0; i < n; i++) {
        int here = pref[i] + bst[i];
        if(i > 0) here -= x * psum[i - 1];
        ans = max(ans, here);
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