//
// b.cpp
// Created by Wasif on 10/19/25 at 09:33:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<string, int> f;
    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        f[s]++;
    }
    vector<int> occ;
    for(auto [s, c]: f) occ.push_back(c);
    sort(occ.rbegin(), occ.rend());
    int x = 0, y = 0;
    for(int i = 0; i < occ.size(); i++) {
        x += occ[i] * a[i];
    }
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < occ.size(); i++) {
        y += occ[i] * a[i];
    }
    cout << x << " " << y << '\n';
}