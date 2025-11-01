//
// a.cpp
// Created by Wasif on 09/13/25 at 20:29:31.
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
        int x, n;
        cin >> x >> n;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1) ans -= x;
            else ans += x;
        }
        cout << ans << '\n';
    }
}