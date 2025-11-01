//
// d.cpp
// Created by Wasif on 09/24/25 at 16:29:25.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int fact[200005], mod = 998244353;

int power(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int inverse(int x) {
    return power(x, mod - 2);
}

int ncr(int n, int r) {
    if(r > n) return 0;
    int ans = fact[n];
    ans = (ans * inverse(fact[r])) % mod;
    ans = (ans * inverse(fact[n - r])) % mod;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for(int i = 1; i <= 2e5; i++) fact[i] = (fact[i - 1] * i) % mod;
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool fl = false;
        for(int i = (n + 1) / 2; i < n; i++) {
            if(a[i] != 0) {
                fl = true;
                break;
            }
        }
        if(fl) {
            cout << 0 << '\n';
            continue;
        }
        if(n & 1) {
            if(a[n / 2] > 1) {
                cout << 0 << '\n';
                continue;
            }
        }
        int ans = 1, sum = 0;
        if(n & 1) sum = a[n / 2];
        for(int i = n / 2 - 1; i >= 0; i--) {
            int opt = 2 * (n / 2 - i) + (n & 1);
            int rem = opt - sum;
            if(i == 0 && rem != a[i]) {
                ans = 0;
            }
            sum += a[i];
            ans = (ans * ncr(rem, a[i])) % mod;
        }
        cout << ans << '\n';
    }
}