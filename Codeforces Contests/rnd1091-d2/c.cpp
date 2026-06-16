//
// c.cpp
// Created by wasifshahzad on 04/07/26 at 20:31:57.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int power(int a, int b, int mod) {
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x, int m) {
    return power(x, m - 2, m);
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int N = n / __gcd(a, n), M = m / __gcd(b, m);
    int q = lcm(N, M);
    if(4 * q == 2 * n * m) {
        cout << "Yes\n";
        return;
    }
    if(__gcd(N, M) != 1) {
        cout << "No\n";
        return;
    }
    int k = -inv(M, N);
    k += N, k %= N;
    q = M * k + n * m;
    if(2 * q + 1 == 2 * n * m) {
        cout << "Yes\n";
        return;
    }
    k = -inv(N, M);
    k += M, k %= M;
    q = N * k + n * m;
    if(2 * q + 1 == 2 * n * m) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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