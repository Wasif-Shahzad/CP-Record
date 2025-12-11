//
// a.cpp
// Created by Wasif on 11/14/25 at 19:24:26.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int f = 0, s = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < x) f++;
        else if(a[i] > x) s++;
    }
    if(f >= s) cout << x - 1 << '\n';
    else cout << x + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}