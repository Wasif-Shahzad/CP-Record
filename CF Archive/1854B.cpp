//
// 1854B.cpp
// Created by Wasif on 09/11/25 at 08:11:40.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 2e5;
using bs = bitset<MAXN + 1>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(2 * n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bs dp;
    if(a[0] == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = a[0], sum = 0;
    for(int i = 1; i <= a[0]; i++) {
        dp[a[i]] = 1;
        sum += a[i];
    }
    ans = max(ans, sum);
    for(int i = a[0] + 1; i < 2 * n; i++) {
        int k = dp._Find_next(max(0ll, i - a[0] - 1));
        if(k == dp.size()) break;
        sum += a[i];
        ans = max(ans, sum - k);
        dp |= dp << a[i];
    }   
    cout << ans << '\n';
}