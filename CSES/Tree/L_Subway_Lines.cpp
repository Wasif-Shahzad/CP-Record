#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define _sz(a) (int)a.size()
#define V vector
#define ff first
#define ss second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define out(a) cout << a << "\n"
#define outv(a) rep(i, 0, (int)a.size()) cout << a[i] << " "; cout << endl;
#define in(a) for(auto &i: a) cin >> i;
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;

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
    int cnt[3] = {0};
    // For MAX: use -1 or -INF. For SUM/GCD/XOR: use 0. For MIN: use INF.
    Node(int x = 0, int y = 0, int z = 0) {
        cnt[0] = x, cnt[1] = y, cnt[2] = z;
    } 
    Node operator+(const Node &other) {
        return Node(cnt[0] + other.cnt[0], cnt[1] + other.cnt[1], cnt[2] + other.cnt[2]);
    }
    void apply(const Tag& t) {
        if(t.v == 2) {
            cnt[2] = cnt[0];
            cnt[0] = cnt[1] = 0;
        } else if(t.v == 1) {
            cnt[2] = cnt[1];
            cnt[1] = cnt[0];
            cnt[0] = 0;
        } else if(t.v == -1) {
            cnt[0] = cnt[1], cnt[1] = cnt[2];
            cnt[2] = 0;
        } else if(t.v == -2) {
            cnt[0] = cnt[2];
            cnt[1] = cnt[2] = 0;
        }
    }
};

struct LazySeg {
    int n;
    vector<Node> t;
    vector<Tag> lazy;

    LazySeg() = default;
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

// --- 3. HLD Template (Integrated) ---
// Make sure to change the Node constructor inside build()
template<bool VALS_IN_EDGES> struct HLD {
    int N, ti;
    vector<int> par, root, depth, sz, pos, rpos;
    vector<vector<int>> adj;
    LazySeg tree;
    HLD(int _N) : N(_N), ti(0), par(_N), root(_N), depth(_N), 
                  sz(_N), pos(_N), adj(_N) {}
    void ae(int u, int v) { 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    void build(int R = 0) {
        par[R] = depth[R] = 0; ti = 0;
        rpos.clear(); rpos.reserve(N);
        dfsSz(R); 
        root[R] = R; 
        dfsHld(R);
        vector<Node> initialNodes(N);
        for(int i=0; i<N; ++i) initialNodes[i] = Node(1, 0, 0); 
        tree = LazySeg(initialNodes);
    }
    void dfsSz(int x) {
        sz[x] = 1;
        for (int& y : adj[x]) {
            par[y] = x; depth[y] = depth[x]+1;
            adj[y].erase(find(adj[y].begin(), adj[y].end(), x)); 
            
            dfsSz(y); sz[x] += sz[y];
            if (sz[y] > sz[adj[x][0]]) swap(y, adj[x][0]);
        }
    }
    void dfsHld(int x) {
        pos[x] = ti++; 
        rpos.push_back(x); 
        for (int y : adj[x]) {
            root[y] = (y == adj[x][0] ? root[x] : y);
            dfsHld(y);
        }
    }
    template<class F>
    void processPath(int u, int v, F op) {
        while (root[u] != root[v]) {
            if (depth[root[u]] < depth[root[v]]) swap(u, v);
            op(pos[root[u]], pos[u]);
            u = par[root[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u] + VALS_IN_EDGES, pos[v]);
    }
    void modifyPath(int u, int v, int val) {
        processPath(u, v, [&](int l, int r) { 
            tree.update(l, r + 1, Tag(val)); 
        });
    }
    int queryPath(int u, int v) {
        int res = 0;
        processPath(u, v, [&](int l, int r) { 
            res = res + tree.query(l, r + 1).cnt[2]; 
        });
        return res;
    }
    void modifySubtree(int x, int val) {
        tree.update(pos[x] + VALS_IN_EDGES, pos[x] + sz[x], Tag(val));
    }
    int querySubtree(int x) {
        return tree.query(pos[x] + VALS_IN_EDGES, pos[x] + sz[x]).cnt[2];
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    HLD<false> hld(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld.ae(u, v);
    }
    hld.build(0);
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        hld.modifyPath(a, b, 1);
        hld.modifyPath(c, d, 1);
        int ans = hld.queryPath(a, b);
        cout << ans << '\n';
        hld.modifyPath(a, b, -1);
        hld.modifyPath(c, d, -1);
    }
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}