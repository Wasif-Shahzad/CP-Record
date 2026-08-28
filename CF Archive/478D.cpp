/*
 * we binary search to find the maximum height that we can get
 * after that for 1...r, we add the ways to make sum of that much with given numbers if remaining can be made with green
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, g;
    cin >> r >> g;
    auto f = [&] (int h) -> bool {
        bitset<400005> bs;
        bs[0] = 1;
        for(int i = 1; i <= h; i++) {
            bs |= bs << i;
        }
        int mx = h * (h + 1) / 2;
        for(int i = 0; i < 400005; i++) {
            if (i <= r && mx - i <= g) return true;
            if (i <= g && mx - i <= r) return true;
        }
        return false;
    };
    int lo = 0, hi = 902;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    int mx = lo * (lo + 1) / 2;
    vector<mint> dp(mx + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= lo; i++) {
        for(int j = mx; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }
    mint ans = 0;
    for(int i = 0; i <= mx; i++) {
        int rem = mx - i;
        if(rem <= g && i <= r) {
            // cout << i << " " << dp[i] << '\n';
            ans += dp[i];
        }
    }
    cout << ans << '\n';
}
