//
// b.cpp
// Created by Wasif on 10/18/25 at 21:50:24.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) cout << 1 << " ";
    cout << b << " ";
    for(int i = 0; i + 1 < n; i++) cout << 1 << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}