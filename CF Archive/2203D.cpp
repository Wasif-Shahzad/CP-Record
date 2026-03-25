//
// 2203D.cpp
// Created by wasifshahzad on 02/25/26 at 23:03:22.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), fa(n + m + 1, 0), cnt(n + m + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        fa[a[i]]++;
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for(int i: a) {
        for(int j = i; j <= n + m; j += i) {
            cnt[j] += fa[i];
        }
    }
    int our = 0, his = 0, mix = 0;
    for(int i: b) {
        if(cnt[i] == n) {
            our++;
        } else if(cnt[i] == 0) {
            his++;
        } else {
            mix++;
        }
    }
    int us = (mix + 1) / 2 + our, them = mix / 2 + his;
    cout << (us > them ? "Alice" : "Bob") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}