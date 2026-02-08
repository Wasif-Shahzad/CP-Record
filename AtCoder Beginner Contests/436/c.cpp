//
// c.cpp
// Created by wasifshahzad on 12/13/25 at 17:17:37.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    set<pair<int, int>> has;
    while(m--) {
        int x, y;
        cin >> x >> y;
        if(has.count({x, y})) continue;
        if(has.count({x + 1, y})) continue;
        if(has.count({x, y + 1})) continue;
        if(has.count({x + 1, y + 1})) continue;
        ans++;
        has.insert({x, y});
        has.insert({x + 1, y});
        has.insert({x, y + 1});
        has.insert({x + 1, y + 1});
    }
    cout << ans << '\n';
}