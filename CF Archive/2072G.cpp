//
// 2072G.cpp
// Created by wasifshahzad on 12/13/25 at 11:45:46.
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

mint floorSum(int n, int L, int R) {
    R = min(R, n);
    mint sum = 0;
    for(int l = L, r; l <= R; l = r + 1) {
        int v = n / l;
        r = (v == 0 ? n : n / v);
        int up = min(R, r);
        sum += (up - l + 1) * v;
    }
    return sum;
}

mint rev(int n, int p) {
    vector<int> digs;
    int tmp = n;
    while(tmp > 0) {
        digs.push_back(tmp % p);
        tmp /= p;
    }
    mint res = 0, x = 1;
    for(int i = digs.size() - 1; i >= 0; i--) {
        res += x * digs[i];
        x *= p;
    }
    return res;
}

mint sum(int l, int r) {
    return r * (r + 1) / 2 - l * (l - 1) / 2;
}

mint sqSum(int l, int r) {
    return (mint)r * (r + 1) * (2 * r + 1) / 6 - (mint)l * (l - 1) * (2 * l - 1) / 6;
}

mint flSqSum(int n, int L, int R) {
    // sum(x^2 * floor(n / x))
    mint res = 0;
    for(int l = L, r; l <= R; l = r + 1) {
        int v = n / l;
        r = n / v;
        r = min(r, R);
        mint contrib = sqSum(l, r) * v;
        res += contrib;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        mint ans = 0;
        ans += max(0ll, k - n) * rev(n, n + 1);
        int x = (int)sqrtl(n);
        if(x * x <= n) x++;
        for(int i = 2; i < min(k + 1, x); i++) {
            ans += rev(n, i);
        }
        x = max(x, 2ll);
        int r = min(n, k);
        if(x <= r) {
            ans += n * sum(x, r);
            ans += floorSum(n, x, r);
            ans -= flSqSum(n, x, r);
        }
        cout << ans << '\n';
    }
}