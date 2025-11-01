//
// b.cpp
// Created by wasifshahzad on 8/26/25 at 09:07:34.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ans += min(a[i], b[i]);
    }
    while (q--) {
        char t;
        int i, x;
        cin >> t >> i >> x;
        i--;
        ans -= min(a[i], b[i]);
        if (t == 'A') {
            a[i] = x;
            ans += min(a[i], b[i]);
        } else {
            b[i] = x;
            ans += min(a[i], b[i]);
        }
        cout << ans << '\n';
    }
}