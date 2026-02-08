//
// 1557C.cpp
// Created by wasifshahzad on 01/11/26 at 22:25:16.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

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
using mint = modint<MOD1>; // check mod

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<array<mint, 2>> dp(k + 1, {-1, -1});
        vector<array<int, 2>> vis(k + 1, {0, 0});
        if(k == 0) {
            cout << 1 << '\n';
            continue;
        }
        auto f = [&] (int i, bool tight, auto&& self) -> mint {
            if(i == -1) return 1;
            if(vis[i][tight]) return dp[i][tight];
            vis[i][tight] = 1;
            if(tight) {
                if(n & 1) {
                    mint sub = mint(2).pow(n - 1) + 1;
                    return dp[i][tight] = sub * self(i - 1, 1, self);
                } else {
                    mint ways = self(i - 1, 0, self);
                    mint other = mint(2).pow(n - 1) - 1;
                    other *= self(i - 1, 1, self);
                    return dp[i][tight] = ways + other;
                }
            } else {
                return dp[i][tight] = mint(2).pow(n) * self(i - 1, 0, self);
            }
        };
        cout << f(k - 1, 1, f) << '\n';
    }
}