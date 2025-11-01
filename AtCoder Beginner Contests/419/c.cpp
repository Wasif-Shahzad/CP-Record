//
// Created by wasifshahzad on 8/16/25.
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
    int maxx = 0, minx = 1e9+6;
    int maxy = 0, miny = 1e9+6;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        maxx = max(maxx, a[i].first);
        maxy = max(maxy, a[i].second);
        minx = min(minx, a[i].first);
        miny = min(miny, a[i].second);
    }
    int dx = maxx - minx;
    int dy = maxy - miny;
    int ans = max((dx + 1) / 2, (dy + 1) / 2);
    cout << ans << '\n';
}