#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    LazySeg() : n(0) {}
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
     *  we color root blue and make bipartite with red.
     *  -> we can make two copies of this. in one, root would be positive. in this we don't consider the nodes which don't have same color as root
     *  -> in other, we don't consider nodes with same color as roots.
     *  this two copies are for adding positives
     *  -> similarly in other copy of the first of the trees before, we only consider nodes which have same color as root and use this for adding -ves
     *  -> and other copy for adding -ves to those who don't have same color as root
     *  it can be that we find the tree where we are positive. add to the subtree.
     */
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int time = 0;
    vector<int> tin(n), tout(n), depth(n, 0);
    auto dfs = [&] (int v, int p, auto&& self) -> void {
        tin[v] = time++;
        for(int c: g[v]) {
            if(c == p) continue;
            depth[c] = depth[v] + 1;
            self(c, v, self);
        }
        tout[v] = time++;
    };
    dfs(0, -1, dfs);
    vector<Node> tmp(time + 1, Node(0, 1));
    LazySeg root_pos(tmp), root_pos_skip(tmp), root_neg(tmp), root_neg_skip(tmp);
    while(m--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, v;
            cin >> x >> v;
            x--;
            int l = tin[x], r = tout[x] + 1;
            if(depth[x] & 1) {
                // opposite color as root
                root_pos_skip.update(l, r, Tag(v));
                root_neg.update(l, r, Tag(v));
            } else {
                // same color as root
                root_pos.update(l, r, Tag(v));
                root_neg_skip.update(l, r, Tag(v));
            }
        } else {
            int x;
            cin >> x;
            x--;
            int i = tin[x];
            int ans = a[x];
            if(depth[x] & 1) {
                ans += root_pos_skip.query(i, i + 1).v;
                ans -= root_neg_skip.query(i, i + 1).v;
            } else {
                ans += root_pos.query(i, i + 1).v;
                ans -= root_neg.query(i, i + 1).v;
            }
            cout << ans << '\n';
        }
    }
}
