//
// f.cpp
// Created by Wasif on 12/12/25 at 09:05:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 2e5, K = 6, mod = 998244353;
vector<bool> isPrime(N + 1, 1);
int w[N + 1];

int power(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(isPrime[i]) {
            w[i]++;
            for(int j = 2 * i; j <= N; j += i) {
                isPrime[j] = 0;
                w[j]++;
            }
        }
    }

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), freq(n + 1, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        vector<vector<int>> dp(n + 1, vector<int>(2 * K + 1, 0)), cnt(n + 1, vector<int>(K + 1, 0));
        for(int i = 1; i <= n; i++) {
            cnt[i][w[i]] += freq[i];
            for(int j = 2 * i; j <= n; j += i) {
                cnt[i][w[j]] += freq[j];
            }
        }
        for(int i = n; i > 0; i--) {
            for(int x = 0; x <= K; x++) {
                for(int y = x; y <= K; y++) {
                    int here = (x == y ? cnt[i][x] * (cnt[i][x] - 1) / 2 : cnt[i][x] * cnt[i][y]);
                    dp[i][x + y] += here;
                }
            }
            for(int s = 0; s <= 2 * K; s++) {
                for(int j = 2 * i; j <= n; j += i) {
                    dp[i][s] -= dp[j][s];
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 2 * K; j++) {
                int binom = power(j - w[i], k);
                int contrib = ((binom % mod) * (dp[i][j] % mod)) % mod;
                ans = (ans + contrib) % mod;
            }
        }
        cout << ans << '\n';
    }
}