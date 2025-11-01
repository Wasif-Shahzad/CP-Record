//
// f.cpp
// Created by Wasif on 11/01/25 at 12:46:49.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto f = [&] (int x) -> bool {
        int tk = k, i = n;
        while(x > 0 && tk > 0 && i > 0) {
            while(i - 1 >= 0 && a[i - 1] > x) i--;
            if(i == 0) return true;
            x -= i;
            tk--;
        }
        return x > 0;
    };
    int lo = 0, hi = n * k + 1;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}