//
// a2.cpp
// Created by Wasif on 10/18/25 at 22:17:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct DSU {
    vector<int> p;
    int comp;

    DSU(int n) { p.resize(n, -1); comp = n; }

    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) { return find(x) == find(y); }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        comp--; return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto f = [&] (int h) -> bool{
        DSU dsu(n + 1);
        for(int i = 0; i < n; i++) {
            if(a[i] <= h) dsu.merge(n, i);
            if(i + 1 < n && abs(a[i] - a[i + 1]) <= h) dsu.merge(i, i + 1);
            if(i && abs(a[i] - a[i - 1]) <= h) dsu.merge(i, i - 1);
        }
        for(int i = 0; i < n; i++) {
            if(!dsu.same_set(i, n)) return false;
        }
        return true;
    };
    int lo = 0, hi = 1e14;
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

    freopen("snake_scales_chapter_2_input.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}