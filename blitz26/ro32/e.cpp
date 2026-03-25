//
// e.cpp
// Created by wasifshahzad on 03/13/26 at 23:53:15.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    a -= c, b -= c;
    if(a < 0 || b < 0) {
        cout << -1 << '\n';
        return;
    }
    int rem = n - a - b - c;
    if(rem <= 0) {
        cout << -1 << '\n';
        return;
    }
    cout << rem << '\n';
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