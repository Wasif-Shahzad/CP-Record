//
// 895C.cpp
// Created by Wasif on 09/12/25 at 09:58:24.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> p1, p2;

const int mod = 1e9+7;

int solve(vector<int>& a, const vector<int>& primes) {
    vector<int> ind(71);
    for(int i = 0; i < primes.size(); i++) {
        ind[primes[i]] = i;
    }
    int n = a.size(), m = primes.size();
    if(n == 0) return 1;
    vector<int> div(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int c = 0;
            while(a[i] % primes[j] == 0) {
                a[i] /= primes[j];
                c++;
            }
            if(c & 1) {
                div[i] += (1 << j);
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>((1 << m), 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        int our = div[i - 1];
        for(int mask = 0; mask < (1 << m); mask++) {
            // not take
            dp[i][mask] = dp[i - 1][mask];
            // take
            dp[i][mask] = (dp[i][mask] + dp[i - 1][mask ^ our]) % mod;
        }
    }
    return dp[n][0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve with prime factors <= 35 and prime factors > 35 separately
    vector<int> isPrime(71, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < 71; i++) {
        if(isPrime[i]) {
            if(i < 35) p1.push_back(i);
            else p2.push_back(i);
            for(int j = i * i; j < 71; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bool up = false;
        for(int p: p2) {
            if(x == p) {
                up = true;
                break;
            }
        }
        if(up) b.push_back(x);
        else a.push_back(x);
    }
    int left = solve(a, p1) - 1, right = solve(b, p2) - 1;
    if(right == 0) cout << left << '\n';
    else if(left == 0) cout << right << '\n';
    else cout << (left * right) % mod << '\n';
}