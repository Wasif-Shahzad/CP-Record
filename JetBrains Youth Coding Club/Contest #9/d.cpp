//
// d.cpp
// Created by Wasif on 12/09/25 at 07:41:49.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> cntX, cntY;
    map<pair<int, int>, int> f;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cntX[x]++, cntY[y]++;
        f[{y, x}]++;
    }
    int ans = 0;
    for(auto [v, c]: cntX) {
        ans += c * (c - 1) / 2;
    }
    for(auto [v, c]: cntY) {
        ans += c * (c - 1) / 2;
    }
    for(auto [v, c]: f) {
        ans -= c * (c - 1) / 2;
    }
    cout << ans << '\n';
}