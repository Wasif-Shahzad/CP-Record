//
// b.cpp
// Created by Wasif on 11/29/25 at 19:30:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n;
    cin >> n;
    map<int, int> f;
    vector<int> even, odd;
    for(int i = 0; i < 2 * n; i++) {
        int x; cin >> x;
        f[x]++;
    }

    for(auto [v, c]: f) {
        if(c & 1) odd.push_back(c);
        else even.push_back(c);
    }

    int o = odd.size(), e = even.size();

    int ans = o + 2 * e;
    if(o == 0) {
        if((n - e) & 1) ans -= 2;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}