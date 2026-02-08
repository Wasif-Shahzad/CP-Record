#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)a.size()
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

void solve(){
    int n;
    cin >> n;
    vector<Node> a(1e5 + 1);
    rep(i, 0, 1e5 + 1) a[i] = Node(0, 1);
    LazySeg seggy(a);
    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        seggy.update(l, r + 1, Tag(1));
    }
    int ans = 0;
    int m; cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        if(seggy.query(l, r + 1).v == 0) {
            ans += r - l + 1;
            seggy.update(l, r + 1, Tag(1));
        }
    }
    out(ans);
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