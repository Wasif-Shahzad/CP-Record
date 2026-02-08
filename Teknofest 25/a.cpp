//
// a.cpp
// Created by wasifshahzad on 01/03/26 at 12:52:03.
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
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (a[i] != b[i]);
    }
    cout << ans;
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