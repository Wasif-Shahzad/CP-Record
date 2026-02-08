//
// c.cpp
// Created by wasifshahzad on 01/06/26 at 18:55:18.
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
struct Tag {
    int v;
    // INITIALIZE with a value which isn't used 
    // it is -1 for range AND
    Tag(int x = -1) : v(x) {}
    void apply(const Tag& other) { if(other.v != -1) v = other.v; }
};

struct Node {
    int v, pref, suff, sm, len;
    // For MAX: use -1 or -INF. For SUM/GCD/XOR: use 0. For MIN: use INF.
    Node(int x = 0, int p = 0, int s = 0, int Sm = 0, int ll = 1) : v(x), pref(p), suff(s), sm(Sm), len(ll) {} 
    Node operator+(const Node &other) {
        Node res;
        res.pref = pref;
        res.suff = other.suff;
        res.v = v + other.v;
        if(suff && other.pref) res.v--;
        res.sm = sm + other.sm;
        res.len = len + other.len;
        return res;
    }
    void apply(const Tag& t) { 
        if(t.v == 0) v = pref = suff = sm = 0;
        else if(t.v == 1) {
            v = pref = suff = 1; 
            sm = len;
        }
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
        if (ql <= l && r <= qr) { 
            apply(v, val); return; 
        }
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
    const int M = 1e6+1, N = 5e5;
    vector<Node> tmp(M);
    LazySeg seggy(tmp);
    int n;
    cin >> n;
    while(n--) {
        char t;
        cin >> t;
        int nt = (t == 'W' ? 0 : 1);
        int l, x;
        cin >> l >> x;
        int r = l + x;
        seggy.update(l + N, r + N, Tag(nt));
        auto res = seggy.query(0, M);
        cout << res.v << " " << res.sm << '\n';
    }
}