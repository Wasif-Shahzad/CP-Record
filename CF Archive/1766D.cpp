//
// 1766D.cpp
// Created by wasifshahzad on 8/27/25 at 11:10:19.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int nxt(int x, int p) {
    return (x + p - 1) / p * p;
}

int spf[10000005];

vector<int> factorize(int x) {
    vector<int> factors;
    while (x != 1) {
        int cur = spf[x];
        factors.push_back(cur);
        while (x % cur == 0) x /= cur;
    }
    return factors;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    iota(spf, spf + 10000005, 0);
    for (int i = 2; i * i <= 1e7; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= 1e7; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (abs(x - y) == 1) {
            cout << -1 << '\n';
            continue;
        }
        auto factors = factorize(abs(x - y));
        int ans = 1e9;
        for (int p: factors) {
            int up = nxt(y, p);
            ans = min(ans, up);
        }
        cout << ans - y << '\n';
    }
}