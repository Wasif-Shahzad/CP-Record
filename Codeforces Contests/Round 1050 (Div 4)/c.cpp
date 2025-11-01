//
// c.cpp
// Created by Wasif on 09/13/25 at 20:50:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int prev = 0, t = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if(b == prev) {
                if(a % 2 == t % 2) ans += a - t;
                else ans += a - t - 1;
                t = a;
            } else {
                if(a % 2 == t % 2) ans += a - t - 1;
                else ans += a - t;
                t = a;
                prev = !prev;
            }
        }
        ans += m - t;
        cout << ans << '\n';
    }
}