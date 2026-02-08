//
// 2137F.cpp
// Created by wasifshahzad on 01/14/26 at 08:10:11.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
if a[i] > b[i] we need a[j] >= a[i] with j < i
if a[i] < b[i] we need a[j] >= b[i] with j < i
*/

struct segtree {
    vector<int> tree;
    int n;

    void init(int _n) {
        int size = 1;
        while(size < _n) size *= 2;
        n = _n;
        tree.assign(2 * size, -1);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if(lx >= l && rx <= r) return tree[x];
        if(lx >= r || rx <= l) return -1;
        int m = (lx + rx) / 2;
        return max(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n);
    }

    void update(int i, int v, int x, int l, int r) {
        if(r - l == 1) {
            tree[x] = v;
            return;
        }
        int m = (l + r) / 2;
        if(i < m) update(i, v, 2 * x + 1, l, m);
        else update(i, v, 2 * x + 2, m, r);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, n);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        segtree seggy;
        seggy.init(2 * n + 1);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) {
                ans += (i + 1) * (n - i);
                seggy.update(a[i], i);
                continue;
            }
            int mx = max(a[i], b[i]);
            int j = seggy.query(mx, 2 * n + 1);
            if(j != -1) {
                ans += (j + 1) * (n - i);
            }
            seggy.update(a[i], i);
        }
        cout << ans << '\n';
    }
}