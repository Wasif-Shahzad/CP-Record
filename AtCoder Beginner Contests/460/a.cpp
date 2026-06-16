//
// a.cpp
// Created by wasifshahzad on 05/30/26 at 16:52:39.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    int asn = 0;
    while(m > 0) {
        m = n % m;
        asn++;
    }
    cout << asn << '\n';
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