//
// 2149B.cpp
// Created by Wasif on 09/26/25 at 08:40:03.
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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = 1; i < n; i += 2) {
            ans = max(ans, a[i] - a[i - 1]);
        }
        cout << ans << '\n';
    }
}