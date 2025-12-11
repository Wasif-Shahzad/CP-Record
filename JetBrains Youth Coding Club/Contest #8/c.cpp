//
// c.cpp
// Created by Wasif on 12/02/25 at 09:40:20.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    if(a > b) swap(a, b);
    if(a <= n / 2 && b > n / 2) {
        cout << "Final!\n";
        return 0;
    }
    int ans = -1;
    for(int rnd = 1; rnd <= __lg(n); rnd++) {
        int k = (1 << rnd);
        for(int i = 1; i + k - 1 <= n; i += k) {
            if(a >= i && b <= i + k - 1) {
                ans = rnd;
                break;
            }
        }
        if(ans != -1) break;
    }
    cout << ans;
}