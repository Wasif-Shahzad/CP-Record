//
// a.cpp
// Created by wasifshahzad on 04/21/26 at 19:34:16.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int x, y;
    cin >> x >> y;
    int lim = y / x;
    if(lim <= 2) cout << "NO\n";
    else cout << "YES\n";
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