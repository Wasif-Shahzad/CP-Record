//
// b.cpp
// Created by wasifshahzad on 04/30/26 at 19:37:39.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int o = count(all(s), ')');
    if(n & 1) {
        cout << "NO\n";
    } else {
        cout << (o == n / 2 ? "YES" : "NO") << '\n';
    }
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