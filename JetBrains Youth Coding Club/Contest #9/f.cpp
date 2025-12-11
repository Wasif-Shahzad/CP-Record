//
// f.cpp
// Created by Wasif on 12/09/25 at 08:22:00.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct segtree{
    vector<int> tree, index;
    int size;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.assign(size * 2, 1e10);
        index.assign(size * 2, -1);
    }

    void update(int i, int j, int v, int x, int l, int r) {
        if(r - l == 1) {
            tree[x] = v;
            index[l] = j;
            return;
        }
        int m = (l + r) / 2;
        if(i < m) update(i, j, v, 2 * x + 1, l, m);
        else update(i, j, v, 2 * x + 2, m, r);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v, int j) {
        update(i, j, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if(lx >= l && rx <= r) return tree[x];
        if(lx >= r || rx <= l) return 1e10;
        int m = (lx + rx) / 2;
        int left = query(l, r, 2 * x + 1, lx, m);
        int right = query(l, r, 2 * x + 2, m, rx);
        return min(left, right);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    int find(int x, int i, int l, int r) {
        if(r - l == 1) return l;
        int m = (l + r) / 2;
        int left = query(l, m);
        if(left < x) return find(x, 2 * i + 1, l, m);
        return find(x, 2 * x + 2, m, r);
    }

    int find(int x) {
        return find(x, 0, 0, size);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    segtree seggy;
    seggy.init(n + 1);
    int c = -1;
    vector<int> nxt(n + 1, n), lst(n + 1, -1);

    for(int i = 0; i < n; i++) {
        int mn = seggy.query(0, n);
        if(mn >= a[i]) {
            c++;
            seggy.update(c, a[i], i);
            lst[c] = i;
        } else {
            int j = seggy.find(a[i]);
            int idx = seggy.index[j];
            seggy.update(j, a[i], i);
            nxt[idx] = i;
        }
    }

    vector<int> vis(n, 0);
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        int j = i;
        ans.emplace_back();
        while(j < n) {
            vis[j] = 1;
            ans.back().push_back(a[j]);
            j = nxt[j];
        }
    }

    for(auto v: ans) {
        for(int i: v) cout << i << " ";
        cout << '\n';
    }
}