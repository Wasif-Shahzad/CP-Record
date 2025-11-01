//
// Created by wasifshahzad on 8/18/25.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
 * brute force is 3^n * n
 * we need used, unused, current turn
 * we need to do with bitmask
 * some reduce the ternary to binary
 *
 */

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> dp(1 << n, {100, 1e15});
    dp[0] = make_pair(0, 0);
    for (int i = 0; i < (1 << n); i++) {
        auto [c, w] = dp[i];
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) continue;
            if (w + a[j] <= x) {
                dp[i | (1 << j)] = min(dp[i | (1 << j)], make_pair(c, w + a[j]));
            } else {
                dp[i | (1 << j)] = min(dp[i | (1 << j)], make_pair(c + 1, a[j]));
            }
        }
    }
    cout << dp[(1 << n) - 1].first + 1 << "\n";
}