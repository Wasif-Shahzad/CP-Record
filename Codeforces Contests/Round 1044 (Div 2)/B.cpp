//
// B.cpp
// Created by wasifshahzad on 8/24/25 at 20:20:01.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
 * 1 0 5 2
 * 1 0 3 0
 */

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 1 + (n & 1); i < n; i += 2) {
            ans += a[i];
        }
        if (n & 1) ans += a[0];
        cout << ans << '\n';
    }
}