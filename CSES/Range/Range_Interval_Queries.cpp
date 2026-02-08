#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

// --- Fast I/O Start ---
namespace FastIO {
    const int BS = 1 << 20; // Buffer Size
    char buf[BS], *p1 = buf, *p2 = buf;
    char pbuf[BS], *pp = pbuf;

    inline char gc() {
        if (p1 == p2) {
            p2 = (p1 = buf) + fread(buf, 1, BS, stdin);
            if (p1 == p2) return EOF;
        }
        return *p1++;
    }

    template<typename T> void read(T &x) {
        x = 0; bool f = 0; char c = gc();
        while (c < '0' || c > '9') { if (c == '-') f = 1; c = gc(); }
        while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = gc(); }
        if (f) x = -x;
    }

    inline void push(const char c) {
        if (pp - pbuf == BS) fwrite(pbuf, 1, BS, stdout), pp = pbuf;
        *pp++ = c;
    }

    template<typename T> void write(T x) {
        if (x < 0) push('-'), x = -x;
        static int stk[35], top = 0;
        do stk[top++] = x % 10, x /= 10; while (x);
        while (top) push(stk[--top] ^ 48);
        push('\n'); 
    }

    inline void flush() {
        fwrite(pbuf, 1, pp - pbuf, stdout);
    }
}
using namespace FastIO;
// --- Fast I/O End ---

#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)a.size()
#define V vector
#define ff first
#define ss second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define out(a) write(a) 
#define outv(a) rep(i, 0, (int)a.size()) { write(a[i]); push(' '); } push('\n');
#define in(a) for(auto &i: a) read(i);
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;

struct segtree {
    int n;
    vector<vector<int>> tree;
    void init(int _n) {
        int s = 1;
        while(s < _n) s *= 2;
        tree.resize(2 * s);
        n = _n;
    }

    void build(vector<int>& a, int x, int l, int r) {
        if(r - l == 1) {
            if(l < a.size()) {
                tree[x].pb(a[l]);
            }
            return;
        }
        int m = (l + r) / 2;
        build(a, 2 * x, l, m);
        build(a, 2 * x + 1, m, r);
        tree[x].resize(r - l);
        merge(all(tree[2 * x]), all(tree[2 * x + 1]), tree[x].begin());
    }

    void build(vector<int>& a) {
        build(a, 1, 0, n);
    }

    int query(int lx, int rx, int x, int l, int r, int v) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            int j = upper_bound(all(tree[x]), v) - tree[x].begin();
            return j;
        }
        int m = (lx + rx) / 2;
        int left = query(lx, m, 2 * x, l, r, v);
        int right = query(m, rx, 2 * x + 1, l, r, v);
        return left + right;
    }

    int query(int l, int r, int v) {
        return query(0, n, 1, l, r, v);
    }
};

void solve(){
    int n, q;
    read(n); 
    read(q);
    V<int> a(n);
    in(a); 
    segtree seggy;
    seggy.init(n);
    seggy.build(a);
    while(q--) {
        int l, r, x, y;
        read(l); 
        read(r); 
        read(x); 
        read(y);
        l--;
        int ans = seggy.query(l, r, y);
        ans -= seggy.query(l, r, x - 1);
        write(ans); 
    }
}

signed main(){
    int t = 1;
    // read(t); 
    while(t--){
        solve();
    }
    flush(); 
}