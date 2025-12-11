//
// b.cpp
// Created by Wasif on 12/05/25 at 19:39:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int minv = -1e16;
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<array<int, 2>> dp1(n, {minv, minv}), dp2(n, {-minv, -minv});
        dp1[0][0] = dp2[0][0] = -a[0];
        dp1[0][1] = dp2[0][1] = b[0];
        for(int i = 1; i < n; i++) {
            dp1[i][0] = dp1[i - 1][0] - a[i];
            dp1[i][1] = dp1[i - 1][1] - a[i];
            dp1[i][0] = max(dp1[i][0], b[i] - dp2[i - 1][1]);
            dp1[i][1] = max(dp1[i][1], b[i] - dp2[i - 1][0]);

            dp2[i][0] = dp2[i - 1][0] - a[i];
            dp2[i][1] = dp2[i - 1][1] - a[i];
            dp2[i][0] = min(dp2[i][0], b[i] - dp1[i - 1][1]);
            dp2[i][1] = min(dp2[i][1], b[i] - dp1[i - 1][0]);
        }
        cout << max({dp1[n - 1][0], dp1[n - 1][1], dp2[n - 1][0], dp2[n - 1][1]}) << '\n'; 
    }
}