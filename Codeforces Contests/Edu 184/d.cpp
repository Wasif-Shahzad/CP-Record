//
// d.cpp
// Created by Wasif on 11/14/25 at 19:24:24.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    auto f = [&] (int c) -> bool {
        if(c < k) return false;
        int mv = x;
        while(c >= k && mv > 0) {
            int vals = c / y;
            if(vals == 0) return true;
            c -= vals;
            mv--;
            if(c < k) return false;
        }
        return c >= k;
    };
    int lo = 0, hi = 1e12 + 1;
    if(!f(1e12)) {
        cout << -1 << '\n';
        return;
    }
    while(hi > lo + 1) {
        int mid = (lo + hi) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}