//
// f.cpp
// Created by wasifshahzad on 04/30/26 at 20:20:35.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

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
    Tag(int x = 0) : v(x) {}
    void apply(const Tag& other) { v += other.v; }
};

struct Node {
    int v, len;
    // For MAX: use -1 or -INF. For SUM/GCD/XOR: use 0. For MIN: use INF.
    Node(int x = 0, int ll = 0) : v(x), len(ll) {} 
    Node operator+(const Node &other) {
        return Node(v + other.v, len + other.len);
    }
    void apply(const Tag& t) { v += len * t.v; }
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

    void upd(int i, Node v, int x, int l, int r) {
        if(r - l == 1) {t[x] = v; return;}
        push(x);
        int m = (l + r) / 2;
        if(i < m) upd(i, v, 2 * x, l, m);
        else upd(i, v, 2 * x + 1, m, r);
        t[x] = t[2*x] + t[2*x+1];
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
    void update(int i, Node v) { upd(i, v, 1, 0, n); }
    Node query(int l, int r) { return qry(1, 0, n, l, r); }
};

void solve() {
    // for a block at height h, its the last occurence of a tower with a[j] >= h (a[n + 1] = n + 1)
    // sum of all last occurences - i - 1
    // segment tree
    // decreasing ai only affects height ai
    // till ak such that ak >= ai
    // all of them will get what we got for ai i.e. last[a[i]] - i - 1
    // 1 2 3 2 1
    // 1 2 3 1 2
    // 1 2 1 2 3
    // 1 1 2 2 3
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<Node> cur(n + 1, Node(n, 1));
    LazySeg seggy(cur);
    vector<int> rng(n);
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans += seggy.query(1, a[i] + 1).v - a[i] * (i + 1);
        rng[i] = seggy.query(a[i], a[i] + 1).v;
        seggy.update(1, a[i] + 1, Tag(-1));
    }
    stack<pair<int, int>> s;
    vector<int> lst(n, -1);
    for(int i = 0; i < n; i++) {
        while(s.size() && s.top().first < a[i]) s.pop();
        if(s.size()) {
            lst[i] = s.top().second;
        }
        s.push({a[i], i});
    }
    vector<Node> tmp(n + 1, Node(0, 1));
    LazySeg freq(tmp);
    freq.update(1, a[0] + 1, 1);
    int oans = ans;
    for(int i = 1; i < n; i++) {
        int here = oans + freq.query(a[i], a[i] + 1).v;
        ans = max(ans, here);
        freq.update(1, a[i] + 1, 1);
    }
    cout << ans << '\n';
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