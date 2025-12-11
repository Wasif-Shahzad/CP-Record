//
// 2171G.cpp
// Created by Wasif on 11/22/25 at 12:07:46.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 1e6+3;
    vector<int> f(mod);
    f[0] = 1;
    for(int i = 1; i < mod; i++) {
        f[i] = f[i - 1] * i % mod;
    }

    auto pow = [&] (int x, int p) -> int {
        int ans = 1;
        while(p > 0) {
            if(p & 1) ans = ans * x % mod;
            x = x * x % mod;
            p /= 2;
        }
        return ans;
    };

    auto inverse = [&] (int x) -> int {
        return pow(x, mod - 2) % mod;
    };

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int mult = 50;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) {
                mult = 0;
                break;
            }
            for(int j = 25; j >= 0; j--) {
                if(a[i] * (1 << j) <= b[i]) {
                    mult = min(mult, j);
                    break;
                }
            }
        }
        int p = 1;
        for(int i = 1; i <= mult; i++) p *= 2;
        // x * 2 <= b[i]
        // x = floor(b[i] / 2)
        int ans = 1, x = 0;
        for(int k = 0; k <= mult; k++) {
            int add = 0;
            vector<int> val(n);
            for(int i = 0; i < n; i++) {
                int up = b[i] / p;
                val[i] = up - a[i];
                add += up - a[i];
                a[i] = up;
                if(k != mult) a[i] *= 2;
            }
            x += add;
            if(add >= mod) {
                ans = 0;
                continue;
            }
            int opt = f[add];
            for(int i = 0; i < n; i++) {
                int div = inverse(f[val[i]]) % mod;
                opt = (opt * div) % mod;
            }
            ans = (ans * opt) % mod;
            p /= 2;
        }
        cout << x + mult << " " << ans << '\n';
    }
}