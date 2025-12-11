//
// f.cpp
// Created by Wasif on 11/23/25 
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 4e3+5;
    int M = 1e5+5;
    int mod = 1e9+7;
    int n;
    cin >> n;
    vector<vector<int>> cnt(N, vector<int>(N, 0));
    vector<vector<int>> recvArr(N, vector<int>(N, 0));
    vector<int> F(M, 0);
    vector<int> invF(M, 0);
    auto power = [&](int a, int b) -> int {
        int ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    };
    auto inv = [&](int x) -> int {
        return power(x, mod - 2) % mod;
    };
    F[0] = 1;
    invF[0] = 1;
    for (int i = 1; i < M; i++) {
        F[i] = (F[i - 1] * i) % mod;
        invF[i] = inv(F[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cnt[2000 - x][2000 - y] += 1;
        recvArr[2000 + x][2000 + y] += 1;
        int a = 2 * x + 2 * y;
        int b = 2 * x;
        int comb = 0;
        if (b >= 0 && b <= a) {
            comb = F[a];
            comb = (comb * invF[b]) % mod;
            comb = (comb * invF[a - b]) % mod;
        }
        sum -= comb;
        sum %= mod;
        sum += mod;
        sum %= mod;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0) {
                cnt[i][j] = (cnt[i][j] + cnt[i - 1][j]) % mod;
            }
            if (j > 0) {
                cnt[i][j] = (cnt[i][j] + cnt[i][j - 1]) % mod;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += (cnt[i][j] * recvArr[i][j]) % mod;
            sum %= mod;
        }
    }
    sum = (sum * inv(2)) % mod;
    cout << sum << '\n';
}
