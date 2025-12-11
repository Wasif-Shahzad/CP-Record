//
// 1627D.cpp
// Created by Wasif on 11/28/25 at 11:49:55.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
we try to add all distinct prime factors which have more than 2 multiples
won't work with [6, 12]
issue arises when gcd(a[i], a[j]) isn't a prime number

gcd(a[i], a[j]) = p * q
[a[i], a[j], p * q]
we can't do more operations

we first add all non-prime gcds
then all prime gcds
*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 1000000;
    int n;
    cin >> n;
    vector<int> a(n), freq(MAXN + 1, 0), mult(MAXN + 1, 0), prime(MAXN + 1, 1);
    vector<long long> dp(MAXN + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    prime[0] = prime[1] = 0;
    for(int i = 2; i <= MAXN; i++) {
        if(prime[i]) {
            for(long long j = 1ll * i * i; j <= MAXN; j += i) {
                prime[j] = 0;
            }
        }
    }

    auto compute = [&] () -> void {
        int m = a.size();
        for(int i = 0; i < m; i++) {
            freq[a[i]]++;
            mult[a[i]]++;
        }
        for(int i = 1; i <= MAXN; i++) {
            for(int j = 2 * i; j <= MAXN; j += i) {
                mult[i] += freq[j];
            }
        }

        for(int i = MAXN; i > 0; i--) {
            dp[i] = 1ll * mult[i] * (mult[i] - 1) / 2;
            for(int j = 2 * i; j <= MAXN; j += i) {
                dp[i] -= dp[j];
            }
        }
    };
    compute();

    for(int i = 4; i <= MAXN; i++) {
        if(freq[i] == 0 && !prime[i] && dp[i]) {
            a.push_back(i);
        }
    }
    
    while(true) {
        int p = a.size();
        freq.assign(MAXN + 1, 0);
        mult.assign(MAXN + 1, 0);
        dp.assign(MAXN + 1, 0ll);
        
        compute();
        
        for(int i = 2; i <= MAXN; i++) {
            if(dp[i] && !freq[i]) {
                a.push_back(i);
            }
        }
        if(!freq[1] && dp[1]) a.push_back(1);
        if((int)a.size() == p) break;
    }

    int m = a.size();
    cout << m - n << '\n';
}