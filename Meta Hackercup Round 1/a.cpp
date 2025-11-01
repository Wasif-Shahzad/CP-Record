//
// a.cpp
// Created by Wasif on 10/18/25 at 21:50:05.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    for(int tt= 1; tt<= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i) ans = max(ans, abs(a[i] - a[i - 1]));
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
}