//
// 2165B.cpp
// Created by Wasif on 12/08/25 at 15:55:17.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 998244353;
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1, 0);
        vector<int> a(n);
        int mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            mx = max(mx, cnt[a[i]]);
        }
        int skip = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        vector<int> dp(n * n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            if(i == skip) continue;
            if(!cnt[i]) continue;
            for(int j = n; j >= cnt[i]; j--) {
                dp[j] = (dp[j] + (dp[j - cnt[i]] * cnt[i]) % mod) % mod;
            }
        }
        vector<int> dp2(n * n + 1, 0);
        dp2[mx] = mx;
        for(int i = 1; i <= n; i++) {
            if(i == skip) continue;
            if(!cnt[i]) continue;
            for(int j = n; j >= cnt[i]; j--) {
                dp2[j] = (dp2[j] + (dp2[j - cnt[i]] * cnt[i]) % mod) % mod;
            }
        }
        int ans = 0;
        for(int i = mx; i <= n * n; i++) {
            ans = (ans + dp[i]) % mod;
            ans = (ans + dp2[i]) % mod;
        }
        cout << ans << '\n';
    }
}