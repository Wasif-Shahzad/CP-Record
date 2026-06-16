//
// 1313C2.cpp
// Created by wasifshahzad on 06/11/26 at 18:47:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

struct segtree {
    int n;
    vector<pair<int, int>> tree;

    segtree(int size) {
        n = 1;
        while(n < size) {
            n *= 2;
        }
        tree.resize(2 * n, {1e10, 0});
        for(int i = 0; i < 2 * n; i++) tree[i].second = i;
    }

    void build(int l, int r, int x, vector<int>& a) {
        if(r - l == 1) {
            if(l < (int)a.size()) {
                tree[x].first = a[l];
                tree[x].second = l;
            }
            return;
        }
        int m = (l + r) / 2;
        build(l, m, 2 * x, a);
        build(m, r, 2 * x + 1, a);
        tree[x] = min(tree[2 * x], tree[2 * x + 1]);
    }

    pair<int, int> query(int lx, int rx, int x, int l, int r) {
        if(lx >= l && rx <= r) {
            return tree[x];
        }
        if(lx >= r || rx <= l) return {1e10, 0};
        int m = (lx + rx) / 2;
        auto left = query(lx, m, 2 * x, l, r);
        auto right = query(m, rx, 2 * x + 1, l, r);
        return min(left, right);
    }

    void build(vector<int>& a) { build(0, n, 1, a); }
    pair<int, int> query(int l, int r) { return query(0, n, 1, l, r); }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segtree seggy(n);
    seggy.build(a);
    vector<int> choice(n, 0);
    auto find = [&] (int l, int r, auto&& self) -> int {
        if(r < l) return 0;
        auto [val, i] = seggy.query(l, r + 1);
        int left = (i - l + 1) * val + self(i + 1, r, self);
        int right =  (r - i + 1) * val + self(l, i - 1, self);
        if(left > right) {
            choice[i] = -1;
        } else {
            choice[i] = 1;
        }
        return max(left, right);
    };
    find(0, n - 1, find);
    vector<int> ans(n);
    auto build = [&] (int l, int r, auto&& self) -> void {
        if(r < l) return;
        auto [val, i] = seggy.query(l, r + 1);
        if(choice[i] == -1) {
            for(int j = l; j <= i; j++) ans[j] = a[i];
            self(i + 1, r, self);
        } else {
            for(int j = i; j <= r; j++) ans[j] = a[i];
            self(l, i - 1, self);
        }
    };
    build(0, n - 1, build);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}