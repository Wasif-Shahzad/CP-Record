//
// a.cpp
// Created by wasifshahzad on 04/08/26 at 19:24:06.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    if(n < m) swap(n, m), swap(a, b);
    int ans = min(n, m) * c;
    ans += (n - m) * a;
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