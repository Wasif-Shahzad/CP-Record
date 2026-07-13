//
// 1547F.cpp
// Created by wasifshahzad on 06/18/26 at 11:35:49.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

struct segtree {
    vector<int> tree;
    int n;

    void init(int s) {
        n = 1;
        while(n < s) n *= 2;
        tree.assign(2 * n, 0);
    }

    void build(vector<int>& a, int l, int r, int x) {
        if(r - l == 1) {
            if(l < (int)a.size()) {
                tree[x] = a[l];
            }
            return;
        }
        int m = (r + l) / 2;
        build(a, l, m, 2 * x);
        build(a, m, r, 2 * x + 1);
        tree[x] = __gcd(tree[2 * x], tree[2 * x + 1]);
    }

    int query(int lx, int rx, int x, int l, int r) {
        if(lx >= l && rx <= r) return tree[x];
        if(lx >= r || rx <= l) return 0;
        int m = (lx + rx) / 2;
        int left = query(lx, m, 2 * x, l, r);
        int right = query(m, rx, 2 * x + 1, l, r);
        return __gcd(left, right);
    }

    void build(vector<int>& a) { build(a, 0, n, 1); }
    int query(int l, int r) { return query(0, n, 1, l, r); }
};

void solve() {
    // [a, b, c]
    // [gcd(a, b), gcd(b, c), gcd(c, a)]
    // [gcd(a, b, c), gcd(b, c, a), gcd(c, b, a)]
    // binary search!
    int n;
    cin >> n;
    vector<int> a(n);
    bool diff = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != a[0]) {
            diff = true;
            continue;
        }
    }
    if(not diff) {
        cout << 0 << '\n';
        return;
    }
    for(int i = 0; i < n; i++) a.push_back(a[i]);
    n *= 2;
    segtree seggy;
    seggy.init(n);
    seggy.build(a);

    auto f = [&] (int k) -> bool {
        int f = seggy.query(0, k + 1);
        for(int i = 1; i < n / 2; i++) {
            if(seggy.query(i, i + k + 1) != f) {
                return false;
            }
        }
        return true;
    };
    int lo = 0, hi = n / 2;
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
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}