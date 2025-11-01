//
// 1359D.cpp
// Created by wasifshahzad on 8/24/25 at 11:32:58.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
 * subarray sum which should include k
 *
 */

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> loc(61);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        loc[a[i] + 30].push_back(i);
    }
    vector<int> b(n, -1e7);
    int ans = 0;
    for (int k = -30; k <= 30; k++) {
        if (loc[k + 30].empty()) continue;
        for (const int i: loc[k + 30]) {
            b[i] = k;
        }
        int sum = b[0], mx = b[0];
        for (int i = 1; i < n; i++) {
            sum = max(sum + b[i], b[i]);
            mx = max(mx, sum);
        }
        ans = max(ans, mx - k);
    }
    cout << ans << '\n';
}