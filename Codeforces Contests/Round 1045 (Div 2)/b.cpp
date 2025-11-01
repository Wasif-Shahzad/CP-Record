//
// b.cpp
// Created by wasifshahzad on 8/27/25 at 08:16:23.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
k even to parity doesn't change
k odd is easy
add it to odds and do nothing with evens
k even?
to nearest divisor of 3?
 */

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> isPrime(1e5+5, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for (int i = 2; i * i <= 1e5; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 1e5; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (k & 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 0) cout << a[i] << " ";
                else cout << a[i] + k << " ";
            }
            cout << '\n';
        } else {
            int x = -1;
            for (int p: primes) {
                if (k % p) {
                    x = p;
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                int ans = -1;
                for (int y = 0; y <= 50; y++) {
                    if ((a[i] + y * k) % x == 0) {
                        ans = a[i] + y * k;
                        break;
                    }
                }
                cout << ans << " ";
            }
            cout << '\n';
        }
    }
}