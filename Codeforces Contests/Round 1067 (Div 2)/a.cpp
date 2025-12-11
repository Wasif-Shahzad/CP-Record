//
// a.cpp
// Created by Wasif on 11/29/25 at 19:30:24.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, y, r;
    cin >> n >> y >> r;
    cout << min(n, y / 2 + r) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}