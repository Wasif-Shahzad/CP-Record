//
// f.cpp
// Created by Wasif on 12/07/25 at 11:30:54.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct segtree{
    vector<int> tree;
    int size;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, 0ll);
    }

    void build(vector<int>& a, int x, int l, int r) {
        if(r == l + 1) {
            if(l < a.size()) {
                tree[x] = a[l];
            }
            return;
        }
        int m = (l + r) / 2;
        build(a, 2 * x + 1, l, m);
        build(a, 2 * x + 2, m, r);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if(lx >= l && rx <= r) return tree[x];
        if(lx >= r || rx <= l) return 0;
        int m = (lx + rx) / 2;
        int left = query(l, r, 2 * x + 1, lx, m);
        int right = query(l, r, 2 * x + 2, m, rx);
        return max(left, right);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> loc(n + 1, -1);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        loc[a[i]] = i;
    }

    segtree seggy;
    seggy.init(n);
    seggy.build(a);

    auto f = [&] (int l, int r, int i, auto&& self) -> int {
        if(r <= l + 1) return 0;
        int left = (l < i ? seggy.query(l, i) : 0);
        int right = (r > i ? seggy.query(i + 1, r) : 0);
        int idx1 = loc[left], idx2 = loc[right];
        int goLeft = (left != 0 ? abs(idx1 - i) + self(l, i, idx1, self) : 0);
        int goRight = (right != 0 ? abs(idx2 - i) + self(i + 1, r, idx2, self) : 0);
        return max(goLeft, goRight);
    };

    cout << f(0, n, loc[n], f) << '\n';
}