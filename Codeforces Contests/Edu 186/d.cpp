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
const int mod1 = 1e9, mod2 = 998244353;

template<int M>
struct modint {
 
    static int _pow(int n, int k) {
        int r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }
 
    int v; modint(int n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }
 
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
 
    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(signed) { modint t = *this; return *this += 1, t; }
    modint operator--(signed) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }
 
    // O(logk) modular exponentiation
    modint pow(const int k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
}; 
using mint = modint<mod2>; // check mod

mint fact[51];

void pre() {
    fact[0] = 1;
    rep(i, 1, 51) fact[i] = fact[i - 1] * i;
}

mint ncr(int n, int r) {
    if(r < 0 || n < r) return 0;
    return fact[n] / (fact[r] * fact[n - r]);
}

void solve(){
    int n;
    cin >> n;
    V<int> a(n + 1);
    in(a);
    if(n == 1) {
        out(1);
        return;
    }
    int sm = accumulate(all(a), 0ll);
    int mn = sm / n;
    int extra = (mn > 0 ? sm % (mn * n) : sm);
    int hi = (extra ? mn + 1 : mn);
    mint ans = fact[extra] * fact[n - extra];
    int have = 0, rm = 0;
    rep(i, 1, n + 1) {
        if(a[i] == hi) {
            have++;
            continue;
        }
        if(a[i] > hi) {
            out(0);
            return;
        }
        rm++;
    }
    if(mn == hi) {
        out(fact[n]);
        return;
    }
    ans *= ncr(rm, extra - have);
    out(ans);
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    pre();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}