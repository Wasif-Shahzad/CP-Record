//
// a.cpp
// Created by Wasif on 10/29/25 at 14:21:39.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int ans = n / (a + b + c) * 3;
        n %= (a + b + c);
        if(n == 0) {
            cout << ans << '\n';
            continue;
        }
        if(n > 0 && n <= a) {
            cout << ans + 1 << '\n';
        } else if(n > 0 && n <= a + b) {
            cout << ans + 2 << '\n';
        } else if(n > 0) {
            cout << ans + 3 << '\n';
        }
    }
}