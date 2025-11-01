//
// Created by wasifshahzad on 8/15/25.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
*/

constexpr int mod = 1e9+7;
struct segtree {
    int size;
    vector<int> tree;

    segtree(const int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size, 0);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (rx <= l || lx >= r) return 0;
        int m = (lx + rx) / 2;
        int left = query(l, r, 2 * x + 1, lx, m);
        int right = query(l, r, 2 * x + 2, m, rx);
        return (left + right) % mod;
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    void update(int i, int v, int x, int l, int r) {
        if (r - l == 1) {
            tree[x] = v;
            return;
        }
        int m = (l + r) / 2;
        if (i < m) update(i, v, 2 * x + 1, l, m);
        else update(i, v, 2 * x + 2, m, r);
        tree[x] = (tree[2 * x + 1] + tree[2 * x + 2]) % mod;
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
    int m = b.size();
    segtree seggy(m + 2);
    seggy.update(0, 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int prev = seggy.query(a[i], a[i] + 1);
        int add = seggy.query(0, a[i]);
        seggy.update(a[i], (prev + add) % mod);
        ans = (ans + add) % mod;
    }
    cout << ans << '\n';
} 