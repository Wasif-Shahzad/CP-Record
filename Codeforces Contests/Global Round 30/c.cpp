//
// c.cpp
// Created by Wasif on 11/06/25 at 20:12:43.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> mon(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> mon[i].first;
    }
    for(int i = 0; i < m; i++) {
        cin >> mon[i].second;
    }
    vector<pair<int, int>> ben, non;
    for(int i = 0; i < m; i++) {
        if(mon[i].second > 0) ben.push_back(mon[i]);
        else non.push_back(mon[i]);
    }
    mon = ben;
    int ans = 0;
    sort(mon.begin(), mon.end(), [](auto x, auto y) {
        if(x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });
    multiset<int> ms;
    for(int i: a) ms.insert(i);
    for(auto [b, c]: mon) {
        auto it = ms.lower_bound(b);
        if(it == ms.end()) continue;
        int new_sword = max(c, *it);
        ms.erase(ms.find(*it));
        if(c > 0) ms.insert(new_sword);
        ans++;
    }
    for(auto [b, c]: non) {
        auto it = ms.lower_bound(b);
        if(it == ms.end()) continue;
        ans++;
        ms.erase(ms.find(*it));
    }
    cout << ans << '\n';
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