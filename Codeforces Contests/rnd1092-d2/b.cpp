//
// b.cpp
// Created by wasifshahzad on 04/12/26 at 10:49:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int t, h, u;
    cin >> t >> h >> u;
    int ans = 4 * min(t, u);
    t -= ans / 4, u -= ans / 4;
    int prs = min(h, t / 2);
    ans += prs * 7;
    h -= prs, t -= prs * 2;
    prs = min(t, h);
    ans += prs * 5;
    t -= prs, h -= prs;
    if(t) ans += t * 2 + 1;
    ans += 3 * h + 3 * u;
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