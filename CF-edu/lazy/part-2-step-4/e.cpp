//
// e.cpp
// Created by wasifshahzad on 01/07/26 at 12:09:41.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/**
 * @brief Generic Lazy Segment Tree (0-indexed, half-open intervals [l, r))
 * * @complexity O(N) Build, O(log N) Update/Query
 * * @customization
 * 1. struct Tag: Define update parameters (e.g., add value, set value).
 * - implement `apply(Tag)` to compose new updates onto existing lazy tags.
 * 2. struct Node: Define segment data (e.g., sum, max, len).
 * - implement `operator+` to merge two nodes (child -> parent).
 * - implement `apply(Tag)` to update a node's value based on a tag.
 * 3. Identity Elements: 
 * - Node constructor defaults should represent the identity (Sum=0, Min=INF).
 * - Tag constructor defaults should represent "no update".
 */
const int INF = 2e15;
struct Tag {
    int l, r, t;
    // INITIALIZE with a value which isn't used 
    // it is -1 for range AND
    Tag(int x = -INF, int y = INF, int tt = -1) : l(x), r(y), t(tt) {}
    void apply(const Tag& other) {
        if(other.t == -1) return;
        l = max(l, other.l);
        l = min(l, other.r);

        r = max(r, other.l);
        r = min(r, other.r);
        t = 1;
    }
};

struct Node {
    int v;
    // For MAX: use -1 or -INF. For SUM/GCD/XOR: use 0. For MIN: use INF.
    Node(int x = 0) : v(x) {} 
    Node operator+(const Node &other) {
        return Node(max(v, other.v));
    }
    void apply(const Tag& t) { 
        if(t.t == -1) return;
        if(v < t.l) v = t.l;
        else if(v > t.r) v = t.r;
    }
};

struct LazySeg {
    int n;
    vector<Node> t;
    vector<Tag> lazy;

    LazySeg(int n): n(n), t(4*n), lazy(4*n) {}
    LazySeg(vector<Node> &a): LazySeg(a.size()) { build(a); }

    void apply(int x, const Tag& val) { t[x].apply(val); lazy[x].apply(val); }

    void push(int v) {
        apply(2 * v, lazy[v]); apply(2 * v + 1, lazy[v]);
        lazy[v] = Tag();
    }

    void build(vector<Node> &a, int v, int l, int r) {
        if (l == r - 1) { if(l < (int)a.size()) t[v] = a[l]; return; }
        int m = (l + r) >> 1;
        build(a, v*2, l, m); build(a, v*2+1, m, r);
        t[v] = t[v*2] + t[v*2+1];
    }

    void upd(int v, int l, int r, int ql, int qr, const Tag& val) {
        if (l >= qr || r <= ql) return;
        if (ql <= l && r <= qr) { apply(v, val); return; }
        push(v);
        int m = (l + r) >> 1;
        upd(v*2, l, m, ql, qr, val);
        upd(v*2+1, m, r, ql, qr, val);
        t[v] = t[2*v] + t[2*v+1];
    }

    Node qry(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return Node(); // Returns identity
        if (ql <= l && r <= qr) return t[v];
        push(v);
        int m = (l + r) >> 1;
        return qry(v*2, l, m, ql, qr) + qry(v*2+1, m, r, ql, qr);
    }

    void build(vector<Node>& a) { build(a, 1, 0, n); }
    void update(int l, int r, Tag val) { upd(1, 0, n, l, r, val); }
    Node query(int l, int r) { return qry(1, 0, n, l, r); }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<Node> a(n + 1);
    LazySeg seggy(a);
    while(k--) {
        int t, l, r, h;
        cin >> t >> l >> r >> h;
        if(t == 1) {
            seggy.update(l, r + 1, Tag(h, INF, 1));
        } else {
            seggy.update(l, r + 1, Tag(-INF, h, 2));
        }
        // for(int i = 0; i < n; i++) {
        //     cout << seggy.query(i, i + 1).v << ' ';
        // }
        // cout << '\n';
    }
    for(int i = 0; i < n; i++) {
        cout << seggy.query(i, i + 1).v << ' ';
    }
    cout << '\n';
}