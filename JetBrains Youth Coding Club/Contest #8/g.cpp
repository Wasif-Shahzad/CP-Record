//
// g.cpp
// Created by Wasif on 12/02/25 at 10:25:18.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bitset<501> dp[501];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = k; j >= a[i]; j--) {
            dp[j] = dp[j] | (dp[j - a[i]] | (dp[j - a[i]] << a[i]));
        }
    }

    vector<int> ans;
    for(int j = 0; j <= k; j++) {
        if(dp[k][j]) ans.push_back(j);
    }
    cout << ans.size() << '\n';
    for(int i: ans) cout << i << " ";
    cout << '\n';
}