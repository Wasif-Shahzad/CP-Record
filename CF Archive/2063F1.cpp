#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
const int mod = 998244353;

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
using mint = modint<mod>; // check mod

const int N = 5005;
vector<mint> cat(N);

void solve() {
    int n;
    cin >> n;
    vector<int> mark(2 * n + 1, 0);
    int cur = 0;
    cout << cat[n] << " ";
    for(int q = 0; q < n; q++) {
        int l, r;
        cin >> l >> r;
        cur++;
        for(int i = l + 1; i < r; i++) {
            if(mark[i] == mark[l]) mark[i] = cur;
        } 
        mark[l] = mark[r] = -1;
        vector<int> freq(n + 1, 0);
        for(int i = 0; i <= 2 * n; i++) {
            if(mark[i] == -1) continue;
            freq[mark[i]]++;
        }
        mint ans = 1;
        for(int i = 0; i <= n; i++) {
            if(freq[i] > 0) ans *= cat[freq[i] / 2];
        }
        cout << ans << " ";
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cat[0] = cat[1] = 1;
    for(int i = 2; i < N; i++) {
        cat[i] = 0;
        for(int j = 0; j < i; j++) {
            cat[i] += cat[j] * cat[i - j - 1];
        }
    }
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
