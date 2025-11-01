//
// b.cpp
// Created by Wasif on 09/08/25 at 19:16:55.
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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = n - 1, c = m; i >= max(0ll, n - m); i--, c--) {
            ans += c * a[i];
        }
        cout << ans << '\n';
    }
}