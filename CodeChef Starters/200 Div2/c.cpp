//
// c.cpp
// Created by wasifshahzad on 8/20/25 at 19:39:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int mod = 998244353;

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int inv(const int x) {
    return power(x, mod - 2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(mx + 1, {-1, -1}));
        auto f = [&] (const int i, const int x, const bool turn, auto&& self) -> int {
            if (i == n - 1 && x > 0) {
                return (turn ? inv(x) : 0);
            }
            if (i == n) return turn;
            if (x == 0) {
                return self(i + 1, a[i + 1], turn, self);
            }
            if (dp[i][x][turn] != -1) return dp[i][x][turn];
            int ans = 1;
            for (int y = x; y >= 1; y--) {
                ans = (ans * inv(x)) % mod;
                ans = (ans * self(i, x - y, !turn, self)) % mod;
            }
            return dp[i][x][turn] = ans;
        };
        cout << f(0, a[0], true, f) % mod << '\n';
    }
}